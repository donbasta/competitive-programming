#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> dp(n, INF);
  vector<int> ar(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for(int i = 0; i < n; i++) {
    int pos = lower_bound(dp.begin(), dp.end(), ar[i]) - dp.begin();
    dp[pos] = min(dp[pos], ar[i]); 
  }
  int ans = 1;
  for(int i = n - 1; i >= 0; i--) {
    if(dp[i] < INF) {
      ans = i + 1; break;
    }
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