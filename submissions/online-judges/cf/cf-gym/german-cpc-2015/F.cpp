#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<ll> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
ll N;
ll ans = 1;
unordered_map<ll, ll> mp;
ll MAX = 1e16;
time_t t1, t2;

void factorize(ll x) {
  ll temp = x;
  for(ll i = 2; i * i <= temp; i++) {
    if(temp % i == 0) {
      while(temp % i == 0) {
        temp /= i; mp[i]++;
      }
    }
  }
  if(temp > 1) mp[temp]++;
}

ll largemul(ll a, ll b, ll n) {
  // assert(0 <= a && a < n && 0 <= b && b < n);
  ll r = 0;
  for (; b; b >>= 1, a <<= 1) {
    if (a >= n) a -= n;
    if (b & 1) {
      r += a;
      if (r >= n) r -= n;
    }
  }
  return r;
}

ll fastexp(ll a, ll b, ll n) {
  // assert(0 <= a && a < n && b >= 0);
  ll ret = 1;
  for (; b; b >>= 1, a = largemul(a, a, n))
    if (b & 1) ret = largemul(ret, a, n);
  return ret;
}

bool mrtest(ll n) {
  if (n == 1) return false;
  ll d = n-1;
  int s = 0;
  while ((d & 1) == 0) {
    s++;
    d >>= 1;
  }
  s--;
  if (s < 0) s = 0;
  for (int j = 0; j < (int)A.size(); j++) {
    if (A[j] >= n) continue;
    ll ad = fastexp(A[j], d, n);
    if (ad == 1) continue;
    bool notcomp = false;
    ll a2rd = ad;
    for (int r = 0; r <= s; r++) {
      if(a2rd == n-1) {notcomp = true; break;}
      a2rd = largemul(a2rd, a2rd, n);
    }
    if (!notcomp) {
      return false;
    }
  }
  return true;
}

ll pollard_rho(ll n) {
  int i = 0, k = 2;
  ll x = 3, y = 3; // random seed = 3, other values possible
  while (1) {
    i++;
    x = largemul(x, x, n)-1; // generating function
    if (x < 0) x += n;
    ll d = __gcd(llabs(y - x), n); // the key insight
    if (d != 1 && d != n) return d;
    if (i == k) y = x, k <<= 1;
  }
}

void solve() {
  cin >> N;
  if(mrtest(N)) {
    cout << 2 << '\n';
    return;
  }
  priority_queue<ll> pq;
  pq.push(N);
  while(pq.top() >= MAX) {
    ll now = pq.top(); pq.pop();
    ll a = pollard_rho(now), b = now / a;
    if(a >= MAX && mrtest(a)) {mp[a]++;}
    else pq.push(a);
    if(b >= MAX && mrtest(b)) {mp[b]++;}
    else pq.push(b);
  }
  while(!pq.empty()) {
    ll now = pq.top(); pq.pop();
    factorize(now);
  }
  ll ans = 1;
  for(auto i : mp) {
    ans = ans * (i.second + 1);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}