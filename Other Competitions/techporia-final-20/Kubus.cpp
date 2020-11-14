#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
const int MX = 1200;

void solve() {
  int n;
  cin >> n;

  unordered_map<int, unordered_map<int, vector<pair<int, int>>>> ve;

  for (int id = 0; id < n; id++) {
    int x, y, z, r;
    cin >> x >> y >> z >> r;
    for (int i = x-r; i < x+r; i++) {
      for (int j = z-r; j < z+r; j++) {
        ve[i][j].push_back(make_pair(y-r, y+r-1));
      }
    }
  }

  ll ans = 0;

  for (auto i : ve) {
    for (auto j : ve[i.first]) {
      // if (j.second.empty()) continue;
      auto vve = j.second;
      sort(vve.begin(), vve.end());
      int sz = (int)vve.size();
      int l = vve[0].first, r = vve[0].second;
      for (int k = 1; k < sz; k++) {
        if (vve[k].first > r) {
          ans += 1LL * (r-l+1);
          l = vve[k].first, r = vve[k].second;
        } else {
          r = max(r, vve[k].second);
        }
      }
      ans += (r-l+1);
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