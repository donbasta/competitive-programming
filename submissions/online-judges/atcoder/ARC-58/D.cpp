#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
const ll MOD = 1e9 + 7;

ll fac[2 * N + 69], ifac[2 * N + 69];

ll binpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return binpow(a, MOD - 2);
}

ll C(int a, int b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fac[a];
  ret = (ret * ifac[b]) % MOD;
  ret = (ret * ifac[a - b]) % MOD;
  return ret;
}

void solve() {

  fac[0] = 1;
  for(int i = 1; i <= 2 * N; i++) fac[i] = (fac[i - 1] * i % MOD);
  ifac[2 * N] = inv(fac[2 * N]);
  for(int i = 2 * N - 1; i >= 0; i--) ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;

  int h, w, a, b;
  cin >> h >> w >> a >> b;
  ll ans = 0;
  for(int i = 0; i < w - b; i++) {
    ans = (ans + C(a + w - b - 2 - i, a - 1) * C(h - a + b - 1 + i, h - a - 1)) % MOD;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}