#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

ll dp[N + 69];

void solve() {
  int n;
  cin >> n;
  vector<int> ve;
  for(int i = 1; i <= n; i++) {
    int cur;
    cin >> cur;
    ve.emplace_back(cur);
  }
  int l1 = 0, l2 = 0;
  for(int i = 1; i < n; i++) {
    if(ve[i] > ve[i - 1]) {
      dp[i + 1] = 1LL * ve[i] - ve[l1] + dp[l1];
      dp[i + 1] = max(dp[i + 1], 1LL * ve[i] - ve[l1 + 1] + dp[l1 + 1]);
      l2 = i;
    } else if(ve[i] < ve[i - 1]){
      dp[i + 1] = 1LL * ve[l2] - ve[i] + dp[l2];
      dp[i + 1] = max(dp[i + 1], 1LL * ve[l2 + 1] - ve[i] + dp[l2 + 1]);
      l1 = i;
    } else if(ve[i] == ve[i - 1]) {
      dp[i + 1] = dp[i];
    }
  }
  cout << dp[n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}