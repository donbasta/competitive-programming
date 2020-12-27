#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

long long largemul(long long a, long long b, long long n) {
  // assert(0 <= a && a < n && 0 <= b && b < n);
  long long r = 0;
  for (; b; b >>= 1, a <<= 1) {
    if (a >= n) a -= n;
    if (b & 1) {
      r += a;
      if (r >= n) r -= n;
    }
  }
  return r;
}

long long fastexp(long long a, long long b, long long n) {
  // assert(0 <= a && a < n && b >= 0);
  long long ret = 1;
  for (; b; b >>= 1, a = largemul(a, a, n))
    if (b & 1) ret = largemul(ret, a, n);
  return ret;
}

bool mrtest(long long n) {
  if (n == 1) return false;
  long long d = n-1;
  int s = 0;
  while ((d & 1) == 0) {
    s++;
    d >>= 1;
  }
  s--;
  if (s < 0) s = 0;
  for (int j = 0; j < (int)A.size(); j++) {
    if (A[j] >= n) continue;
    long long ad = fastexp(A[j], d, n);
    if (ad == 1) continue;
    bool notcomp = false;
    long long a2rd = ad;
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

long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

long long pollard_rho(long long n) {
  int i = 0, k = 2;
  long long x = 3, y = 3; // random seed = 3, other values possible
  while (1) {
    i++;
    x = largemul(x, x, n)-1; // generating function
    if (x < 0) x += n;
    long long d = gcd(llabs(y - x), n); // the key insight
    if (d != 1 && d != n) return d;
    if (i == k) y = x, k <<= 1;
  }
}

const int N = 1e6;
const ll INF = 1e18;
bool pr[N + 10];
map<ll, int> isPP, cntPP;
map<ll, vector<int>> contPP;

void sieve() {
  int N = 1e6;
  for (int i = 2; i <= N; i++) pr[i] = 1;
  for (int i = 2; i <= N; i++) {
    if (!pr[i]) continue;
    for (int j = i + i; j <= N; j += i) {
      pr[j] = 0;
    }
  }
}

int n, k;

void solve() {
  sieve();

  cin >> n >> k;
  for (int i = 2; i <= N; i++) {
    if (!pr[i]) continue;
    ll cur = i;
    while (1) {
      isPP[cur] = i;
      if (cur >= ((INF + i) / i) )
        break;
      cur = cur * i;
    }
  }
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (isPP.find(x) != isPP.end()) {
      cntPP[x]++;
    } else {
      if (mrtest(x)) {
        cntPP[x]++;
      } else {
        ll p = pollard_rho(x);
        if (p * p == x) cntPP[x]++;
      }
    }
  }
  int tot = 0;
  for (auto i : cntPP) {
    if (i.second >= 2) tot += i.second;
  }
  if (tot >= k) {
    cout << 
  }



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