#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int M = 500;
int n, k;
int dp[M + 5][M + 5];
int pre[M + 5];


void solve() {
  cin >> n >> k;
  k--;
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      int tmp = 0;
      for (int k = i - 1; k >= max(i - j, j); k--) {
        tmp = (tmp + dp[k][j]) % MOD;
      }
      for (int k = min(i - j, j - 1); k >= 1; k--) {
        tmp = (tmp + dp[i - j][k]) % MOD;
      }
      dp[i][j] = tmp;
    }
  }
  for (int i = 1; i <= n; i++) {
    // cerr << i << ' ' << dp[n][i] << '\n';
    pre[i] = (pre[i - 1] + dp[n][i]) % MOD;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int j = min(n, k / i);
    ans = (2LL * dp[n][i] * pre[j] + ans) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
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