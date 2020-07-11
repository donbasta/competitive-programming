#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m;
int ar[60][60];

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
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        cin >> ar[i][j];
      }
    }
    int col = 0, row = 0;
    for(int i = 1; i <= n; i++) {
      bool ok = true;
      for(int j = 1; j <= m; j++) {
        ok &= (ar[i][j] == 0);
      }
      if(ok)
        row++;
    }
    for(int i = 1; i <= m; i++) {
      bool ok = true;
      for(int j = 1; j <= n; j++) {
        ok &= (ar[j][i] == 0);
      }
      if(ok)
        col++;
    }
    int lol = min(row, col);
    if(lol & 1)
      cout << "Ashish";
    else
      cout << "Vivek";
    cout << '\n';
  }

  return 0;
}
