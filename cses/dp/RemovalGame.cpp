#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 5e3;
const ll INF = 1e18;

int n;
ll ar[N + 2];
ll dp[N + 2][N + 2][2];

void solve() {

  for(int i = 0; i < N + 2; i++) {
    for(int j = 0; j < N + 2; j++) {
      for(int k = 0; k < 2; k++) {
        dp[i][j][k] = -INF;
      }
    }
  }

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    dp[1][i][0] = ar[i];
    dp[1][i][1] = 0;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= n - i + 1; j++) {
      dp[i][j][0] = max(ar[j] + dp[i - 1][j + 1][1], dp[i - 1][j][1] + ar[j + i - 1]);
      dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j + 1][0]);
    }
  }
  cout << dp[n][1][0] << '\n';
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