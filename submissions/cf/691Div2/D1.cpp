#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
int a[N + 5], b[N + 5];
int sum;

int gab(int x, int y, int z) {
  int l = 2 * a[z], r = sum + b[z];
  for (auto i : ve[x][y]) {
    l += 2 * a[i];
    r += b[i];
  }
  return min(l, r);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sum += b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int A = dp[i - 1][j];
      int B = gab(i - 1, j - 1, i);
      if (A < B) {
        dp[i][j] = 
      } else if (A >= B) {
        dp[i][j]
      }
    }
  }
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