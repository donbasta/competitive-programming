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

  int tc;
  cin >> tc;
  while(tc--) {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if(a + b < n + m) {
      cout << "No";
    } else {
      ll mini = min(a, b);
      if(m <= mini) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    }
    cout << '\n';
  }

  return 0;
}
