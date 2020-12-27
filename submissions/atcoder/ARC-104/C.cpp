#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1), b(n + 1);
  vector<int> ada(2 * n + 1, 0);
  vector<vector<bool>> dp(2 * n + 1, vector<bool>(2 * n + 1));
  vector<int> nx(2 * n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if(a[i] > 0) ada[a[i]]++;
    if(b[i] > 0) ada[b[i]]++;
    if(a[i] > 0 && b[i] > 0) {
      nx[a[i]] = b[i], nx[b[i]] = a[i];
      if(a[i] >= b[i]) {
        cout << "No" << '\n';
        return;
      }
    }
  }
  for(int i = 1; i <= 2 * n; i++) {
    if(ada[i] > 1) {
      cout << "No" << '\n';
      return;
    }
  }
  for(int i = 1; i < 2 * n; i += 2) {
    if(ada[i] && ada[i + 1]) {
      if(nx[i] == i + 1 && nx[i + 1] == i) {
        dp[i][2] = 1;
      } else {
        dp[i][2] = 0;
      }
    } else if(ada[i]) {
      if(nx[i] > 0) {
        dp[i][2] = 0;
      } else {
        dp[i][2] = 1;
      }
    } else if(ada[i + 1]) {
      if(nx[i + 1] > 0) {
        dp[i][2] = 0;
      } else {
        dp[i][2] = 1;
      }
    } else {
      dp[i][2] = 1;
    }
  }
  for(int i = 4; i <= 2 * n; i += 2) {
    for(int j = 1; j <= 2 * n - i + 1; j += 2) {
      for(int k = 2; k < i; k += 2){
        dp[j][i] = dp[j][i] || (dp[j][k] && dp[j + k][i - k]);
      }
    }
  }
  cout << (dp[1][2 * n] ? "Yes" : "No") << '\n';
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