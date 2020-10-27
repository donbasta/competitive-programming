#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> ar(n + 1, vector<int>(3));
  vector<vector<int>> dp(n + 1, vector<int>(3));
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> ar[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      int nj = (j + 1) % 3, njj = (nj + 1) % 3;
      dp[i][j] = max(dp[i - 1][nj], dp[i - 1][njj]) + ar[i][j];
    }
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}