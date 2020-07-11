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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int lol = k / n;
    int rem = k % n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < lol; j++) {
        ans[i][(i + j) % n] = 1;
      }
    }
    for(int i = 0; i < rem; i++) {
      ans[i][(i + lol) % n] = 1;
    }
    if(rem == 0) {
      cout << 0 << '\n';
    } else {
      cout << 2 << '\n';
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
