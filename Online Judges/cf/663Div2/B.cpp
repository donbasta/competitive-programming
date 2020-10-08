#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  string s[n];
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n - 1; i++) {
    if(s[i][m - 1] != 'D')
      ans++;
  }
  for(int i = 0; i < m - 1; i++) {
    if(s[n - 1][i] != 'R')
      ans++;
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