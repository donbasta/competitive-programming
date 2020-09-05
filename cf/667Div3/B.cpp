#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll a, b, x, y, n, ans = 1e18;
  cin >> a >> b >> x >> y >> n;
  if(a - x + b - y <= n) {
    ans = x * y;
  } else {
    if(n >= (a - x)) {
      ll u = a - x;
      ll uu = n - u;
      b -= uu;
      ans = min(ans, x * b);
    }
    if(n >= (b - y)) {
      ll v = b - y;
      ll vv = n - v;
      a -= vv;
      ans = min(ans, y * a);
    }
    if(b - n >= y) ans = min(ans, a * (b - n));
    if(a - n >= x) ans = min(ans, b * (a - n));
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