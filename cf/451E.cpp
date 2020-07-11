#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int n;
ll s, INV = 1, f[20];

ll C(ll a, ll b) {
  if(a < b)
    return 0;
  ll ret = 1;
  for(int i = 0; i < b; i++) {
    ret = (ret * ((a - i) % MOD)) % MOD;
  }
  ret = (ret * INV) % MOD;
  return ret;
}

ll modpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = (ret * a) % MOD;}
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return modpow(a, MOD - 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> s;
  for(int i = 1; i < n; i++) {
    INV = (INV * i) % MOD;
  }
  INV = inv(INV);
  for(int i = 0; i < n; i++) {
    cin >> f[i];
  }
  ll ans = 0;
  for(int i = 0; i < (1 << n); i++) {
    ll temp = s;
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if((i >> j) & 1) {
        cnt++;
        temp -= (f[j] + 1);
      }
    }
    if(cnt & 1)
      ans = (ans - C(temp + n - 1, n - 1)) % MOD;
    else
      ans = (ans + C(temp + n - 1, n - 1)) % MOD;
  }
  if(ans < 0)
    ans += MOD;
  cout << ans << '\n';
  return 0;
}
