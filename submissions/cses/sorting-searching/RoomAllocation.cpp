#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> ve;
  vector<int> ans(n);
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ve.emplace_back(make_pair(a, b), i);
  }
  sort(ve.begin(), ve.end());
  int tot = 0;
  multiset<pair<int, int>> se;
  for(int i = 0; i < n; i++) {
    if(se.empty()) {
      ans[ve[i].second] = tot;
      se.emplace(ve[i].first.second, tot++); 
      continue;
    }
    auto earliest = se.begin();
    if(earliest->first >= ve[i].first.first) {
      ans[ve[i].second] = tot;
      se.emplace(ve[i].first.second, tot++);
    } else {
      int room = earliest->second;
      ans[ve[i].second] = room;
      se.erase(earliest);
      se.emplace(ve[i].first.second, room);
    }
  }
  cout << tot << '\n';
  for(int i = 0; i < n; i++) {
    cout << ans[i] + 1 << ' ';
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