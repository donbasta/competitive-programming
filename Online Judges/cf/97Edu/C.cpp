#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

void solve() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  vector<int> dp(2*n), mdp(2*n);
  mdp[0] = INF;
  for (int i = 1; i <= 2 * n - 1; i++) {
    dp[i] = abs(i - t[0]);
    mdp[i] = min(mdp[i-1], dp[i]);
  }
  for (int i = 1; i < n; i++) {
    for (int e = i+1; e <= 2*n - 1; e++) {
      dp[e] = mdp[e-1] + abs(e - t[i]);
    }
    mdp[i+1] = dp[i+1];
    for (int e = i+2; e <= 2*n - 1; e++) {
      mdp[e] = min(mdp[e-1], dp[e]);
    }
  }
  int ans = INF;
  for (int i = n; i <= 2*n - 1; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << '\n';
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