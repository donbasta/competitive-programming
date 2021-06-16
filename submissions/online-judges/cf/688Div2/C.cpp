#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> ar(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      int dig = (int) s[j] - '0'
      ar[i + 1][j + 1] = dig;
      cnt[dig]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      row[i][ar[i][j]].push_back(j);
      col[j][ar[i][j]].push_back(i);
    }
  }
  for (int dig = 0; dig < 10; dig++) {
    if (cnt[dig] <= 1) {
      cout << 0 << ' ';
      continue;
    } else if (cnt[dig] == 2) {
      
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {

    }
    for (int i = 1; i <= n; i++) {

    }
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