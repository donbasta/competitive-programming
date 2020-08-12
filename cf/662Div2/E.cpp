#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

void solve() {
  cin >> n;
  vector<vector<int>> dp(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    int len = (int)s[i].length();
    dp[i].resize(len + 1);
  }
  fill(dp[0].begin(), dp[0].end(), 1);
  for(int i = 1; i < n; i++) {
    for(int j = 0; j <= (int)dp[i].size(); j++) {
      
    }
  }
  int tot = 0;
  for(int i = 0; i <= (int)dp[n - 1].size(); i++) {
    tot = (1LL * tot + dp[n - 1][i]) % MOD;
  }
  if(tot < 0) tot += MOD;
  cout << tot << '\n';
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