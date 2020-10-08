#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[1] = 0;
  dp[2] = 1;
  for(int i = 3; i <= n; i++) {
    dp[i] = 1LL * (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
  }
  if(dp[n] < 0) dp[n] += MOD;
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