#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int n;

void solve() {
  cin >> n;
  string s[n];
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans[n][n];
  memset(ans, 0, sizeof(ans));
  ans[0][0] = (s[0][0] != '*');
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] == '*') continue;
      if(i > 0) ans[i][j] = (1LL * ans[i][j] + ans[i - 1][j]) % MOD;
      if(j > 0) ans[i][j] = (1LL * ans[i][j] + ans[i][j - 1]) % MOD;
    }
  }
  ans[n - 1][n - 1] %= MOD;
  if(ans[n - 1][n - 1] < 0) ans[n - 1][n - 1] += MOD;
  cout << ans[n - 1][n - 1] << '\n';
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