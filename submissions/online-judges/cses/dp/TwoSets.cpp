#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>((n * (n + 1) / 2) + 1));
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= i * (i + 1) / 2; j++) {
      dp[i][j] = dp[i - 1][j];
      if(j >= i)
        dp[i][j] = (1LL * dp[i][j] + dp[i - 1][j - i]) % MOD;
    }
  }
  int lol = n * (n + 1) / 2;
  if(lol & 1) {
    cout << 0 << '\n';
  } else {
    int ans = dp[n][lol / 2] % MOD;
    if(ans < 0) ans += MOD;
    if(ans & 1) ans += MOD;
    ans /= 2;
    cout << ans << '\n';
  }
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