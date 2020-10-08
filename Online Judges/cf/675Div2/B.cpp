#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;

  ll ans = 0;
  vector<vector<ll>> ar(n + 1, vector<ll>(m + 1));
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> ar[i][j];
    }
  }
  for(int i = 1; i <= (n + 1) / 2; i++) {
    for(int j = 1; j <= (m + 1) / 2; j++) {
      int i1 = n + 1 - i, j1 = m + 1 - j;
      if(i == i1 && j == j1) continue;
      if(i == i1) ans += abs(ar[i][j] - ar[i][j1]);
      else if(j == j1) ans += abs(ar[i][j] - ar[i1][j]);
      else {
        vector<ll> temp = {ar[i][j], ar[i][j1], ar[i1][j], ar[i1][j1]};
        sort(temp.begin(), temp.end());
        ans += (temp[3] + temp[2] - temp[1] - temp[0]);
      }
    }
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