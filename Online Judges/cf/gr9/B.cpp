#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ve(n, vector<int>(m));
    bool ok = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int x;
        cin >> x;
        if(((i==0) && (j==0)) || ((i==0) && (j==(m-1))) || ((i==(n-1)) && (j==0)) || ((i==(n-1)) && (j==(m-1)))) {
          if(x > 2)
            ok = false;
          ve[i][j] = 2;
        } else if((i==0) || (i==(n-1)) || (j==0) || (j==(m-1))) {
          if(x > 3)
            ok = false;
          ve[i][j] = 3;
        } else {
          if(x > 4)
            ok = false;
          ve[i][j] = 4;
        }
        // cout << i << ' ' << j << ' ' << ve[i][j] << '\n';
      }
    }
    // cout << tc << ' ' << ok << '\n';
    if(!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    // cout << n << ' ' << m << '\n';
    // cout << tc << '\n';
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cout << ve[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
