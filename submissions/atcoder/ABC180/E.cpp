#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 17;
const ll INF = 1e18;
int n;
ll x[N+5], y[N+5], z[N+5];

inline ll dis(int a, int b) {
  return abs(x[a]-x[b]) + abs(y[a]-y[b]) + max(0LL,z[b]-z[a]);
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  vector<vector<ll>> dp(1<<n, vector<ll>(n, INF));
  dp[1][0] = 0;
  for(int i = 0; i < (1<<n); i++) {
    for(int j = 0; j < n; j++) {
      if(i & (1<<j)) {
        int pr = i ^ (1<<j);
        for(int k = 0; k < n; k++) {
          if(pr & (1<<k))
            dp[i][j] = min(dp[i][j], dp[pr][k] + dis(k,j));
        }
      }
    }
  }
  ll ans = INF;
  for(int i = 1; i < n; i++) {
    ans = min(ans, dp[(1<<n) - 1][i] + dis(i,0));
  }
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