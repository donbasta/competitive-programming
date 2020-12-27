#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll f(ll x) {
  x %= MOD;
  ll ret = x * (x + 1) / 2;
  ret %= MOD;
  return ret;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  ll ans = (f(b) - f(a - 1)) % MOD;
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