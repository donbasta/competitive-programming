#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
const ll MOD = 1e9 + 7;

ll f[N + 5];
ll fac[2 * N + 5], ifc[2 * N + 5];

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if (b&1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD-2);
}

void fill_fibo() {
  f[0] = 0, f[1] = 1;
  for (int i = 2; i <= N; i++) {
    f[i] = (f[i-1] + f[i-2]) % MOD;
  }
}

void fill_fac() {
  fac[0] = 1;
  for (int i = 1; i <= 2*N; i++) {
    fac[i] = (fac[i-1] * i) % MOD;
  }
  ifc[2*N] = inv(fac[2*N]);
  for (int i = 2*N - 1; i >= 0; i--) {
    ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
  }
}

ll C(ll a, ll b) {
  if (a < b || a < 0 || b < 0) return 0;
  ll ret = fac[a];
  ret = ret * ifc[b] % MOD;
  ret = ret * ifc[a-b] % MOD;
  return ret;
}

void solve() {
  fill_fibo();
  fill_fac();

  ll x, y;
  cin >> x >> y;

  ll ans = 0;
  for (int i = 1; i <= x; i++) {
    ans = (ans + f[i] * C(x+y-i-1, y-1)) % MOD;
  }
  for (int i = 1; i <= y; i++) {
    ans = (ans + f[i] * C(x+y-i-1, x-1)) % MOD;
  }
  ans %= MOD;
  if (ans < 0) ans += MOD;
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