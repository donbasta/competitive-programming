#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 1e5;
const int INF = 1e9 + 7;

void solve() {
  int n, W;
  cin >> n >> W;

  vector<ll> w(n + 1), val(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> val[i];
  }

  vector<bool> can(MX + 1);
  vector<ll> dp(MX + 1, INF);
  can[0] = 1;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = MX; j >= 1; j--) {
      int pr = j - val[i];
      if (pr < 0 || !can[pr]) continue;
      dp[j] = min(dp[j], dp[pr] + w[i]);
      can[j] = 1;
    }
  }

  for (int i = MX; i >= 0; i--) {
    if (can[i] && dp[i] <= W) {
      // cerr << dp[i] << '\n';
      cout << i << '\n';
      return;
    }
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