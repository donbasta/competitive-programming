#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
const ll MOD = 1e9 + 7;

ll fac[2 * N + 5], ifac[2 * N + 5];

ll fastexpo(ll a, ll b) {
  ll res = 1;
  while(b) {
    if(b & 1) { res = (res * a) % MOD; }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

void init() {
  fac[0] = 1;
  for(int i = 1; i <= 2 * N; i++) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  ifac[2 * N] = inv(fac[2 * N]);
  for(int i = 2 * N - 1; i >= 0; i--) {
    ifac[i] = ifac[i + 1] * (i + 1) % MOD;
  }
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fac[a];
  ret = ret * ifac[b] % MOD;
  ret = ret * ifac[a - b] % MOD;
  return ret;
}

void solve() {
  init();
  int n, m, g;
  cin >> n >> m >> g;
  if(n + m == 1) {
    if(n == g) { 
      cout << 0 << '\n'; return;
    }
    cout << 1 << '\n'; return;
  }
  if(n + m == 2) {
    if(n == 2) {
      if(g) { cout << 1 << '\n'; return; }
      cout << 0 << '\n'; return;
    } 
    if(n == 1) {
      if(!g) { cout << 2 << '\n'; return; }
      cout << 0 << '\n'; return;
    }
    if(n == 0) {
      if(!g) { cout << 1 << '\n'; return; }
      cout << 0 << '\n'; return;
    }
  }
  if(m == 0) {
    if(n % 2 != g % 2) { cout << 1 << '\n'; return; }
    cout << 0 << '\n'; return;
  }
  if(n == 0) {
    if(!g) { cout << 1 << '\n'; return; }
    cout << 0 << '\n'; return;
  }
  ll start = n + m - 1;
  if(g) start--;
  ll ans = 0;
  while(start >= m - 1) {
    ans = (ans + C(start, m - 1)) % MOD;
    start -= 2;
  }
  if(m == 1 && (n % 2 == g)) { ans--; }
  if(m == 1 && (n % 2 != g)) { ans++; }
  ans %= MOD;
  if(ans < 0) ans += MOD;
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