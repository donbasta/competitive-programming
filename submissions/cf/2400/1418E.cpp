#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
const int MOD = 998244353;

int fc[N + 5], ifc[N + 5];
int d[N + 5];
ll p[N + 5];

int n, m;

int fpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = (1LL * ret * a) % MOD;
    a = (1LL * a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

int inv(int a) {
  return fpow(a, MOD - 2);
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  sort(d + 1, d + 1 + n);
  for (int i = 1; i <= n; i++) {
    p[i] = (p[i - 1] + d[i]) % MOD;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    int t = lower_bound(d + 1, d + n + 1, b) - d;
    int cnt = n - t + 1;
    if (cnt < a) {
      cout << 0 << '\n';
      continue;
    }
    ll ans = 0;
    ll P = p[t - 1];
    ll Q = ((p[n] - P) % MOD + MOD) % MOD;
    ans = (ans + ((1LL * inv(cnt + 1) * (cnt + 1 - a)) % MOD) * P) % MOD;
    if (cnt != 0)
      ans = (ans + ((1LL * inv(cnt) * (cnt - a)) % MOD) * Q) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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