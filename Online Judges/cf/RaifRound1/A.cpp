#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll dx = abs(x1 - x2), dy = abs(y1 - y2);
  ll ans;
  if(dx == 0) {
    ans = dy;
  } else if(dy == 0) {
    ans = dx;
  } else {
    ans = dx + dy + 2;
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