#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  int ans = 1e9;
  vector<vector<int>> r(3, vector<int>(n + 1)), g(3, vector<int>(n + 1)), b(3, vector<int>(n + 1));

  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      r[i][j] = r[i][j - 1] + ((s[j - 1] != 'R') && (j % 3 == i));
      g[i][j] = g[i][j - 1] + ((s[j - 1] != 'G') && (j % 3 == i));
      b[i][j] = b[i][j - 1] + ((s[j - 1] != 'B') && (j % 3 == i));
    }
  }

  for (int i = 0; i < 3; i++) {
    int ni = (i + 1) % 3, nni = (ni + 1) % 3;
    for (int j = k; j <= n; j++) {
      int change = r[i][j] - r[i][j - k] + g[ni][j] - g[ni][j - k] + b[nni][j] - b[nni][j - k];
      ans = min(ans, change);
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}