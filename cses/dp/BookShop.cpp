#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, x;

void solve() {
  cin >> n >> x;
  vector<int> dp(x + 1), h(n), s(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = x; j >= 1; j--) {
      int sisa = j - h[i];
      if(sisa < 0) continue;
      dp[j] = max(dp[j], dp[sisa] + s[i]);
    }
  }
  int ans = 0;
  for(int i = 1; i <= x; i++) {
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