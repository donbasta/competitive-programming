#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> ar(3, vector<int>(n));
  vector<int> ans(n);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      cin >> ar[i][j];
    }
  }
  
  int pos = 0;
  ans[0] = ar[pos][0];
  for(int i = 1; i < n - 1; i++) {
    if(ar[pos][i] == ans[i - 1]) {
      pos = (pos + 1) % 3;
    }
    ans[i] = ar[pos][i];
  }
  if(ar[pos][n - 1] == ans[0] || ar[pos][n - 1] == ans[n - 2]) {
    pos = (pos + 1) % 3;
  } 
  if(ar[pos][n - 1] == ans[0] || ar[pos][n - 1] == ans[n - 2]) {
    pos = (pos + 1) % 3;
  } 
  ans[n - 1] = ar[pos][n - 1];
  for(int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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