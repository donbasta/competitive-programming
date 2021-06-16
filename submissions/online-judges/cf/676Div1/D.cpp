#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  vector<ll> c(7);
  ll x, y;
  cin >> x >> y;
  for(int i = 1; i <= 6; i++) {
    cin >> c[i];
  }
  ll ans = 0;
  if(x == 0) {
    if(y >= 0) {
      ans = c[2] * y;
    } else {
      ans = c[5] * y * (-1);
    }
  } else if(y == 0) {
    if(x >= 0) {
      ans = c[6] * x;
    } else {
      ans = c[3] * x * (-1);
    }
  } else if(x == y) {
    if(x >= 0) {
      ans = c[1] * x;
    } else {
      ans = c[4] * x * (-1);
    }
  } else {
    if(y > x && x > 0) {
      ans = min((y - x) * c[2] + x * c[1], y * c[1] + (y - x) * c[3]);
    } else if(x < 0 && y > 0) {
      ans = min(y * c[2] - x * c[3], (y - x) * c[3] + y * c[1]);
    } else if(y < 0 && x < y) {
      ans = min()
    } else if(x < 0 && x > y) {
      ans = min()
    } else if(x > 0 && y < 0) {
      ans = min()
    } else if(x > y && y > 0) {
      ans = min()
    }
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