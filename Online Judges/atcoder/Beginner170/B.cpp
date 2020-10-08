#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int x, y;
  cin >> x >> y;

  bool ok = true;
  ok &= (y % 2 == 0);
  ok &= (y >= 2 * x);
  ok &= (4 * x >= y);
  cout << (ok ? "Yes" : "No");
  cout << '\n';

  return 0;
}
