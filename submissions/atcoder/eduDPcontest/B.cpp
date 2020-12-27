#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<int> dp(n + 1, INF);
  dp[1] = 0;
  for(int i = 2; i <= n; i++) {
    for(int j = i - 1; j >= max(1, i - k); j--) {
      dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
  }
  cout << dp[n] << '\n';
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