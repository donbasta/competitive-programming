#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void upd(int& x, int y) { x = max(x, y); }

const int N = 200;

int n, k;
string s, t;
int dp[N + 5][N + 5][N + 5];

void solve() {
  cin >> n >> k;
  cin >> s >> t;
  if(t[0] == t[1]) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == t[0]) { cnt++; }
    }
    int lol = min(n, cnt + k);
    int ans = lol * (lol - 1) / 2;
    cout << ans << '\n';
    return;
  }
  vector<int> pre(n + 1);
  for(int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + (s[i - 1] == t[0]); }
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  dp[0][1][s[0] == t[0]] = 1;
  int cnt = (s[0] == t[0]);
  for(int i = 2; i <= n; i++) {
    if(s[i - 1] == t[1]) { dp[0][i][cnt] = dp[0][i - 1][cnt] + cnt; }
    else if(s[i - 1] == t[0]) { cnt++; dp[0][i][cnt] = dp[0][i - 1][cnt - 1]; }
    else { dp[0][i][cnt] = dp[0][i - 1][cnt]; }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= min(i, k); j++) {
      for(int r = 0; r <= i; r++)
      if(s[i - 1] == t[0]) { 
        if(r > 0) upd(dp[j][i][r], dp[j][i - 1][r - 1]);
        if(r > 0 && dp[j - 1][i - 1][r - 1] != -1) upd(dp[j][i][r], dp[j - 1][i - 1][r - 1] + r - 1); 
      } else if(s[i - 1] == t[1]) {
        if(dp[j][i - 1][r] != -1) upd(dp[j][i][r], dp[j][i - 1][r] + r);
        if(r > 0) upd(dp[j][i][r], dp[j - 1][i - 1][r - 1]);
      } else {
        upd(dp[j][i][r], dp[j][i - 1][r]);
        if(r > 0) upd(dp[j][i][r], dp[j - 1][i - 1][r - 1]);
        if(dp[j - 1][i - 1][r] != -1) upd(dp[j][i][r], dp[j - 1][i - 1][r] + r);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      cerr << i << ' ' << j << ' ' << dp[j][n][i] << '\n';
      upd(ans, dp[j][n][i]);
    }
  }
  cout << ans << '\n';
  return;
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