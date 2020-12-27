#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int x, y;
  cin >> x >> y;
  x = abs(x), y = abs(y);
  if (x < y) swap(x, y);
  int ans = 2 * x;
  if (x != y) ans--;
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