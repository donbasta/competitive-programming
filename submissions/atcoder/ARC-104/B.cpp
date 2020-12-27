#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  int n;
  cin >> n;
  cin >> s;

  // int n = (int)s.length();
  vector<vector<int>> pre(n + 1, vector<int>(4));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 4; j++) {
      pre[i + 1][j] = pre[i][j];
    }
    if(s[i] == 'A') pre[i + 1][0]++;
    if(s[i] == 'C') pre[i + 1][1]++;
    if(s[i] == 'G') pre[i + 1][2]++;
    if(s[i] == 'T') pre[i + 1][3]++;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      int t[4];
      for(int k = 0; k < 4; k++) {
        t[k] = pre[j][k] - pre[i - 1][k];
      }
      // cerr << i << ' ' << j << '\n';
      // for(int i = 0; i < 4; i++) { cerr << t[i] << ' '; }
      // cerr << '\n';
      ans += ((t[0] == t[3]) && (t[1] == t[2]));
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