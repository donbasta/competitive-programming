#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

char dp[105][105];

char winner(char a, char b) {
  if (a == b) return a;
  if (a == 'R') {
    if (b == 'P') return 'P';
    if (b == 'S') return 'R';
  }
  if (a == 'P') {
    if (b == 'R') return 'P';
    if (b == 'S') return 'S';
  }
  if (a == 'S') {
    if (b == 'P') return 'S';
    if (b == 'R') return 'R';
  }
  return a;
}

int fpow(int a, int b, int mod) {
  int ret = 1;
  while(b) {
    if (b & 1) {ret = (1LL * ret * a) % mod;}
    a = (1LL * a * a) % mod;
    b >>= 1;
  }
  return ret;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    dp[i][0] = s[i];
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      char u = dp[j][i - 1];
      int nx = (j + fpow(2, i - 1, n)) % n; 
      char v = dp[nx][i - 1];
      dp[j][i] = winner(u, v);
    }
  }
  cout << dp[0][k] << '\n';
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