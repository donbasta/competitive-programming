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

  ld PI = acos(-1);
  ll r;
  cin >> r;
  ld ans = (ld) r * 2 * PI;
  cout << fixed << setprecision(12) << ans << '\n';

  return 0;
}
