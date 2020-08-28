#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a; 
    ll l, r;
    cin >> a >> l >> r;
    ve[a].emplace_back(l, r);
  }
  for(int i = 0; i < 3; i++) {
    sort(ve[i].begin(), ve[i].end());
  }
  vector<pair<ll, pair<int, int>> all;
  for(int i = 0; i < 3; i++) {
    if(ve[i].empty()) continue;
    ll l = ve[i][0].first, r = ve[i][0].second;
    vector<pair<ll, ll>> temp;
    for(int j = 1; j < (int)ve[i].size(); j++) {
      if(ve[i][j].first <= r)
        r = max(r, ve[i][j].second);
      else {
        all.emplace_back(l, make_pair(i, 1));
        all.emplace_back(r, make_pair(i, 0));
        l = ve[i][j].first, r = ve[i][j].second;
      }
    }
    temp.emplace_back(l, r);
    ve[i] = temp;
  }
  for(int i = 0; i )

  sort(all.begin(), all.end());
  for()

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