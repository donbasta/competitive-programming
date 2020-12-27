#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
  cin >> n >> m;
  vector<pair<int, int>> ve;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ve.emplace_back(x, y);
  }
  sort(ve.begin(), ve.end());
  int l = ve[0].first, r = ve[0].second;
  int ans = m - 1;
  for(int i = 1; i < n; i++) {
    if(r >= m) break;
    if(ve[i].first > r) {
      ans -= (r - l);
      l = ve[i].first, r = ve[i].second;
    } else {
      r = max(r, ve[i].second);
    }
  }
  if(l < m) ans -= (min(m, r) - l);
  cout << ans << '\n';
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