#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3 + 5;

int n, m;
int a[N], b[N], dp[N][N];

int solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(a[i] == b[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int lcs = dp[n][m];
  int ret = n + m -lcs;
  return ret;
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