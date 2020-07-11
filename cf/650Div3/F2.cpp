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
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    map<>
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ve.emplace_back(x, i);
    }
    sort(ve.begin(), ve.end());



    cout << n - mx << '\n';
  }
  return 0;
}
