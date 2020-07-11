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
    vector<int> ar(2 * n + 1);
    vector<int> ve[2];
    for(int i = 1; i <= 2 * n; i++) {
      int x;
      cin >> x;
      ve[x & 1].push_back(i);
    }
    int lol = n - 1;
    for(int i = 0; i < 2; i++) {
      int sz = ve[i].size();
      if(sz <= 1)
        continue;
      for(int j = 0; j + 1 < sz; j += 2) {
        if(lol == 0)
          break;
        cout << ve[i][j] << ' ' << ve[i][j + 1];
        cout << '\n';
        lol--;
      }
    }
  }

  return 0;
}
