#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int solve() {
  int n;
  cin >> n;
  vector<int> ar(n + 1);
  vector<vector<int>> dp0(n + 1), dp1(n + 1), dp10(n + 1), dp11(n + 1), dp00(n + 1), dp01(n + 1);

  for(int i = 1; i <= n; i++) {
    dp0[i].resize(n + 2 - i);
    dp1[i].resize(n + 2 - i);
    dp00[i].resize(n + 2 - i);
    dp01[i].resize(n + 2 - i);
    dp10[i].resize(n + 2 - i);
    dp11[i].resize(n + 2 - i);
  }
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for(int i = 1; i <= n; i++) {
    dp0[1][i] = dp1[1][i] = ar[i];
    dp00[1][i] = dp01[1][i] = ar[i];
    dp10[1][i] = dp11[1][i] = ar[i];
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j + i - 1 <= n; j++) {
      dp1[i][j] = min(dp00[i - 1][j], dp01[i - 1][j + 1]);
      dp10[i][j] = max(dp10[i - 1][j], dp1[i][j]);
      dp11[i][j] = max(dp11[i - 1][j + 1], dp1[i][j]);

      dp0[i][j] = max(dp10[i - 1][j], dp11[i - 1][j + 1]);
      dp00[i][j] = min(dp00[i - 1][j], dp0[i][j]);
      dp01[i][j] = min(dp01[i - 1][j + 1], dp0[i][j]);
    }
  }
  return dp1[n][1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    cout << solve() << '\n';
  }
  
  return 0;
}