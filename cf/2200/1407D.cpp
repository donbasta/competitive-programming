#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e5;
int dp[N + 5];

void solve() {
  int n;
  cin >> n;
  stack<pair<int, int>> s1, s2;
  {
    int le;
    cin >> le;
    s1.emplace(le, 1), s2.emplace(le, 1);
  }
  for(int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    dp[i] = dp[i - 1] + 1;
    int mx = 0, mn = 2e9;
    while(!s1.empty()) {
      if(s1.top().first > mx) {
        dp[i] = min(dp[s1.top().second] + 1, dp[i]);
      }
      mx = max(mx, s1.top().first);
      if(s1.top().first >= x) {
        break;
      }
      s1.pop();
    }
    while(!s2.empty()) {
      if(s2.top().first < mn) {
        dp[i] = min(dp[s2.top().second] + 1, dp[i]);
      }
      mn = min(mn, s2.top().first);
      if(s2.top().first <= x) {
        break;
      }
      s2.pop();
    }
    s1.emplace(x, i), s2.emplace(x, i);
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