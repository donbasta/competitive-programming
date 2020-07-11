#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 2e5;

string s;
int n;
int fac[2 * N + 10], ifac[2 * N + 10];
ll ans;

int C(int a, int b) {
  if(a < 0 || b < 0 || a < b)
    return 0;
  int ret;
  ret = fac[a];
  ret = (1LL * ret * ifac[b]) % MOD;
  ret = (1LL * ret * ifac[a - b]) % MOD;
  return ret;
}

int modpow(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) {ret = (1LL * ret * a) % MOD;}
    a = (1LL * a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

int inv(int a) {
  return modpow(a, MOD - 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  fac[0] = 1;
  for(int i = 1; i <= 2 * N; i++) {
    fac[i] = (1LL * i * fac[i - 1]) % MOD;
  }
  ifac[2 * N] = inv(fac[2 * N]);
  for(int i = 2 * N - 1; i >= 0; i--) {
    ifac[i] = (1LL * (i + 1) * ifac[i + 1]) % MOD;
  }

  cin >> s;
  n = (int) s.length();
  vector<int> pre(n + 1);
  for(int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + (s[i] == '(');
  }
  for(int i = 1; i < n; i++) {
    if(s[i - 1] == ')')
      continue;
    int x = pre[i] - 1;
    int y = (n - i) - (pre[n] - pre[i]);
    ans = (ans + C(x + y, x + 1)) % MOD;
  }
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';
  return 0;
}
