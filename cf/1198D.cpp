#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const int N = 60;
 
int n;
char c[N][N];
int pre[N][N];
int dp[N][N][N][N];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> c[i][j];
      pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + (c[i][j] == '#');
    }
  }
  for(int x1 = 1; x1 <= n; x1++) {
    for(int x2 = x1; x2 <= n; x2++) {
      for(int y1 = 1; y1 <= n; y1++) {
        for(int y2 = y1; y2 <= n; y2++) {
          dp[x1][x2][y1][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
        }
      }
    }
  }

  for(int cols = 1; cols <= n; cols++) {
    for(int rows = 1; rows <= n; rows++) {
      for(int x1 = 1; x1 + cols - 1 <= n; x1++) {
        for(int y1 = 1; y1 + rows - 1 <= n; y1++) {
          int x2 = x1 + cols - 1, y2 = y1 + rows - 1;
          for(int col = x1; col <= x2; col++) {
            int temp = pre[col][y2] - pre[col - 1][y2] - pre[col][y1 - 1] + pre[col - 1][y1 - 1];
            if(temp != 0)
              continue;
            dp[x1][x2][y1][y2] = min(dp[x1][x2][y1][y2], dp[x1][col - 1][y1][y2] + dp[col + 1][x2][y1][y2]);
          }
          for(int row = y1; row <= y2; row++) {
            int temp = pre[x2][row] - pre[x1 - 1][row] - pre[x2][row - 1] + pre[x1 - 1][row - 1];
            if(temp != 0)
              continue;
            dp[x1][x2][y1][y2] = min(dp[x1][x2][y1][y2], dp[x1][x2][y1][row - 1] + dp[x1][x2][row + 1][y2]);
          }
        }
      }
    }
  }

  int ans = dp[1][n][1][n];
  cout << ans << '\n';
  return 0;
}