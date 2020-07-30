#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a, b, c, x, y, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> a >> b >> c >> x >> y;
  if(2 * c >= a + b) {
    ans = a * x + b * y;
  } else {
    if(x >= y) {
      ans = 2 * c * y + (x - y) * a; 
    } else {
      ans = 2 * c * x + (y - x) * b;
    }
    ans = min(ans, 2 * c * max(x, y));
  }
  cout << ans << '\n';
  
  return 0;
}