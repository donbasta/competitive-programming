#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  string s[n];
  vector<int> cnt(m);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') cnt[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') {
        ok &= (cnt[j] > 1);
      }
    }
    if (ok) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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