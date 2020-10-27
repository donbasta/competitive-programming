#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> h(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<int> dp(n + 1);
  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    if(i > 2) 
      dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
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