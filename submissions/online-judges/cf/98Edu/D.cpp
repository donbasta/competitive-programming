#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 998244353;
const int N = 2e5;

ll fc[N + 5], ifc[N + 5];

ll fpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

ll C(ll a, ll b) {
  if (a < b || a < 0 || b < 0) return 0;
  ll ret = fc[a];
  ret = ret * ifc[a - b] % mod;
  ret = ret * ifc[b] % mod;
  return ret;
}

void init_fac() {
  fc[0] = 1;
  for (int i = 1; i <= N; i++) {
    fc[i] = fc[i - 1] * i % mod;
  }
  ifc[N] = fpow(fc[N], mod - 2);
  for (int i = N-1; i >= 0; i--) {
    ifc[i] = ifc[i + 1] * (i+1) % mod;
  }
}

void solve() {

  init_fac();

  int n;
  cin >> n;

  ll ans = fpow(2LL, n);
  ans = fpow(ans, mod - 2);
  ll sum = 0;
  for (int k = 0; k * 2 <= n; k++) {
    ll A = C(n - k - 1, k);
    sum = (sum + A) % mod;
  }
  ans = (ans * sum) % mod;
  if (ans < 0) ans += mod;
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