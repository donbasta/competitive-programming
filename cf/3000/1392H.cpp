#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e6;
const ll MOD = 998244353;

ll fc[2 * N + 5], ifc[2 * N + 5];
ll ar[N + 5];

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % MOD; }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

void init_fac() {
  fc[0] = 1;
  for(int i = 1; i <= 2 * N; i++) {
    fc[i] = fc[i - 1] * i % MOD;
  }
  ifc[2 * N] = inv(fc[2 * N]);
  for(int i = 2 * N - 1; i >= 0; i--) {
    ifc[i] = ifc[i + 1] * (i + 1) % MOD;
  }
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fc[a];
  ret = ret * ifc[b] % MOD;
  ret = ret * ifc[a - b] % MOD;
  return ret;

}

void solve() {

  init_fac();

  int n, m;
  cin >> n >> m;

  ll temp = (((fc[n] * fc[m]) % MOD) * ifc[n + m]) % MOD;
  for(int i = 1; i <= n; i++) {
    ar[i] = (C(n + m - i, m - 1) * temp) % MOD;
  }
  ll A = 1, B = (n * temp) % MOD;
  for(int i = 1; i <= n; i++) {
    A = (A - ar[i]) % MOD;

    ll cur = (ar[i] * (i)) % MOD;
    B = (B + cur) % MOD;
  }
  if(A < 0) A += MOD;
  if(B < 0) B += MOD;
  ll ans = (B * inv(A)) % MOD;
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