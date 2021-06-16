#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  ll ans = 1e18;
  {
    ll ta = a, tb = b, tn = n;
    ta -= min(n, a - x);
    tn -= min(n, a - x);
    tb -= min(tn, b - y);
    ans = min(ans, ta * tb);
  }
  {
    ll ta = a, tb = b, tn = n;
    tb -= min(n, b - y);
    tn -= min(n, b - y);
    ta -= min(tn, a - x);
    ans = min(ans, ta * tb);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}