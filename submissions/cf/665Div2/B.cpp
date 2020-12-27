#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int a[3], b[3];
  for(int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < 3; i++) {
    cin >> b[i];
  }
  int tot = a[0] + a[1] + a[2];
  int ans;
  if(a[2] > b[1]) {
    ans = 2 * b[1];
    if(b[2] > tot - a[1] - b[1]) {
      ans -= 2 * (b[2] + a[1] + b[1] - tot);
    }
  } else {
    ans = 2 * a[2];
    if(a[1] > tot - a[2] - b[2]) {
      ans -= 2 * (a[1] + a[2] + b[2] - tot);
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