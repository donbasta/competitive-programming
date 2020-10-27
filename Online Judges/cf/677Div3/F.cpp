#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

//dp[baris][banyak][sum mod k]

inline void upd(int& a, int b) { a = max(a, b); }

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> ar(n + 1, vector<int>(m + 1));
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> ar[i][j];
    }
  }
  
  vector<vector<int>> dp(n + 1, vector<int>(k, -1));
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    vector<vector<int>> ndp(m + 1, vector<int>(k, -1));
    ndp[0][0] = 0;
    for(int col = 1; col <= m; col++) {
      int now = ar[i][col];
      for(int j = col; j >= 1; j--) {
        for(int sum = 0; sum < k; sum++) {
          if(ndp[j - 1][sum] != -1)
            upd(ndp[j][(sum + now) % k], ndp[j - 1][sum] + now);
        }
      }
    }
    for(int sum = 0; sum < k; sum++) {
      for(int tot = 0; tot < k; tot++) {
        for(int cnt = m / 2; cnt >= 0; cnt--) {
          if(ndp[cnt][tot] != -1 && dp[i - 1][(sum + k - tot) % k] != -1) {
            upd(dp[i][sum], dp[i - 1][(sum + k - tot) % k] + ndp[cnt][tot]);
          }
        }
      }
    }
  }
  cout << dp[n][0] << '\n';
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