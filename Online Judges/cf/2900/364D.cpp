#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

int n;
unordered_map<ll, bool> udah;
ll ar[N + 5];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll get_rand() { return uniform_int_distribution<int>(0, n)(rng); }

ll largemul(ll a, ll b, ll n) {
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

ll pollard_rho(ll n) {
  int i = 0, k = 2;
  ll x = 3, y = 3;
  while (1) {
    i++;
    x = largemul(x, x, n)-1;
    if (x < 0) x += n;
    ll d = __gcd(llabs(y - x), n);
    if (d != 1 && d != n) return d;
    if (i == k) y = x, k <<= 1;
  }
}

void solve() {
  
  // srand(chrono::steady_clock::now().time_since_epoch().count());

  cin >> n;
  set<ll> se;
  for(int i = 0; i < n; i++) { cin >> ar[i]; se.insert(ar[i]); }
  int sz = (int)se.size();
  ll ans = -1;
  int i = 0;
  while(i < min(sz, 5)) {
    int cur = get_rand() % n;
    cerr << i << ' ' << cur << '\n';
    if(udah.count(ar[cur])) { continue; }
    udah[ar[cur]] = 1;
    i++;
    vector<ll> temp, fact(2, -1);
    
    if(ar[cur] > (ll)1e9) {
      temp.push_back(ar[cur]);
      fact[0] = pollard_rho(ar[cur]);
      fact[1] = ar[cur] / fact[0];
    } else {
      fact[0] = ar[cur];
    }
    
    for(int i = 0; i < 2; i++) {
      if(fact[i] < 0) continue;
      for(ll j = 1; j * j <= ar[cur]; j++) {
        if(ar[cur] % j == 0) { 
          temp.push_back(j); 
          if(j * j != ar[cur]) { temp.push_back(ar[cur] / j); }
        }
      }
    }
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for(int id = (int)temp.size() - 1; id >= 0; id--) {
      ll div = temp[id];
      int cnt = 0;
      for(int j = 0; j < n; j++) {
        cnt += (ar[j] % div == 0);
      }
      if(2 * cnt >= n) { ans = max(ans, div); break; }
    }
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