#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> ve;
  for(int i = 0; i < n; i++) {
    int y;
    cin >> y;
    ve.emplace_back(y, i + 1);
  }
  sort(ve.begin(), ve.end());
  int l = 0, r = n - 1;
  while(l < r) {
    while(l < r && (ve[l].first + ve[r].first > x)) {
      r--;
    }
    while(l < r && (ve[l].first + ve[r].first < x)) {
      l++;
    }
    if(l < r && (ve[l].first + ve[r].first == x)) {
      cout << ve[l].second << ' ' << ve[r].second << '\n';
      return;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
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