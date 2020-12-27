#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, W;
  cin >> n >> W;

  vector<ll> w(n + 1), val(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> val[i];
  }

  vector<bool> can(W + 1);
  vector<ll> dp(W + 1);
  can[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = W; j >= 1; j--) {
      int pr = j - w[i];
      if (pr < 0 || !can[pr]) continue;
      dp[j] = max(dp[pr] + val[i], dp[j]);
      can[j] = 1;
    }
  }
  ll ans = -1;
  for (int i = 1; i <= W; i++) {
    ans = max(ans, dp[i]);
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