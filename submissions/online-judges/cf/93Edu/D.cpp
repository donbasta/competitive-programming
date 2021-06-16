#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200;

ll dp[N + 5][N + 5][N + 5];

void solve() {
  int R, G, B;
  cin >> R >> G >> B;
  vector<ll> r(R + 1), g(G + 1), b(B + 1);
  for(int i = 1; i <= R; i++) {
    cin >> r[i];
  }
  for(int i = 1; i <= G; i++) {
    cin >> g[i];
  }
  for(int i = 1; i <= B; i++) {
    cin >> b[i];
  }
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  for(int i = 1; i <= R; i++) {
    for(int j = 1; j <= G; j++) {
      dp[i][j][0] = r[i] * g[j] + dp[i - 1][j - 1][0];
    }
  }
  for(int i = 1; i <= G; i++) {
    for(int j = 1; j <= B; j++) {
      dp[0][i][j] = g[i] * b[j] + dp[0][i - 1][j - 1];
    }
  }
  for(int i = 1; i <= B; i++) {
    for(int j = 1; j <= R; j++) {
      dp[j][0][i] = b[i] * r[j] + dp[j - 1][0][i - 1];
    }
  }
  for(int i = 1; i <= R; i++) {
    for(int j = 1; j <= G; j++) {
      for(int k = 1; k <= B; k++) {
        dp[i][j][k] = r[i] * g[j] + dp[i - 1][j - 1][k];
        dp[i][j][k] = max(dp[i][j][k], r[i] * b[k] + dp[i - 1][j][k - 1]);
        dp[i][j][k] = max(dp[i][j][k], g[j] * b[k] + dp[i][j - 1][k - 1]);
      }
    }
  }
  cout << dp[R][G][B] << '\n';
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