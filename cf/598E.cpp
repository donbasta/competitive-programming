#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, m, k;
ll dp[35][35][55];

void init() {
  for(int i = 1; i <= 30; i++) {
    for(int j = i; j <= 30; j++) {
      for(int l = 0; l <= min(50, i * j); l++) {
        if(l == 0 || l == i * j){
          dp[i][j][l] = 0;
          continue;
        }
        dp[i][j][l] = 1e9;
        int is = i * i, js = j * j;
        for(int p = 1; p < j; p++){
          for(int q = 0; q <= l; q++){
            if(q > p * i || (l - q) > i * (j - p))
              continue;
            dp[i][j][l] = min(dp[i][j][l], is + dp[min(i, p)][max(i, p)][q] + dp[min(i, j - p)][max(i, j - p)][l - q]);
          }
        }
        for(int p = 1; p < i; p++){
          for(int q = 0; q <= l; q++){
            if(q > j * p || (l - q) > (i - p) * j)
              continue;
            dp[i][j][l] = min(dp[i][j][l], js + dp[min(j, p)][max(j, p)][q] + dp[min(i - p, j)][max(j, i - p)][l - q]);
          }
        }
        // cout << i << ' ' << j << ' ' << dp[i][j][l] << '\n';
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  init();
  while(tc--) {
    cin >> n >> m >> k;
    if(n > m) swap(n, m);
    cout << dp[n][m][k] << '\n';
  }
  return 0;
}
