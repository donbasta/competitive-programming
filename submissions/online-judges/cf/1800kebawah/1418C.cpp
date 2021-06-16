#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) { cin >> a[i]; }
  if(n <= 2) {
    int ans = (a[1] == 1);
    cout << ans << '\n';
    return;
  }
  vector<vector<int>> dp(2, vector<int>(n + 1));
  dp[0][1] = (a[1] == 1);
  dp[0][2] = (a[1] == 1) + (a[2] == 1);
  dp[1][2] = dp[0][1];
  dp[0][3] = dp[1][2] + (a[3] == 1);
  dp[1][3] = dp[0][1];
  for(int i = 4; i <= n; i++) {
    dp[0][i] = dp[1][i - 1] + (a[i] == 1);
    dp[0][i] = min(dp[0][i], dp[1][i - 2] + (a[i] == 1) + (a[i - 1] == 1));
    dp[1][i] = min(dp[0][i - 1], dp[0][i - 2]);
  }
  cout << min(dp[0][n], dp[1][n]) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}