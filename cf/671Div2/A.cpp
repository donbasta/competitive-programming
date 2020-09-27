#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void solve() {
  int n;
  cin >> n;

  vector<vector<int>> cnt(2, vector<int>(2, 0));
  for(int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    int temp = (c - '0');
    cnt[i % 2][temp % 2]++;
  }
  if(n & 1) {
    if(cnt[1][1] > 0) { cout << 1; }
    else { cout << 2; }
  } else {
    if(cnt[0][0] > 0) { cout << 2; }
    else { cout << 1; }
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