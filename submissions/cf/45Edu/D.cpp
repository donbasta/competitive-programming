#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a != 1 && b != 1) {
    cout << "NO" << '\n';
    return;
  }
  if (n == 1 && a == 1 && b == 1) {
    cout << "YES" << '\n' << 0 << '\n';
    return;
  }
  if (n <= 3 && a == 1 && b == 1) {
    cout << "NO" << '\n';
    return;
  }
  vector<vector<int>> ve(n, vector<int>(n));
  if (a == 1 && b == 1) {
    for (int i = 0; i < n - 1; i++) {
      ve[i][i + 1] = ve[i + 1][i] = 1;
    }
  } else if (a == 1) {
    for (int i = 0; i <= n - b; i++) {
      for (int j = 0; j <= n - b; j++) {
        if (i != j) {
          ve[i][j] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        ve[i][j] = 1 - ve[i][j];
      }
    }
  } else if (b == 1) {
    for (int i = 0; i <= n - a; i++) {
      for (int j = 0; j <= n - a; j++) {
        if (i != j) {
          ve[i][j] = 1;
        }
      }
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ve[i][j];
    }
    cout << '\n';
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