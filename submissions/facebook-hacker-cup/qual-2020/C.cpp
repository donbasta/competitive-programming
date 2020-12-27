#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
  unordered_map<int, int> mp;
  vector<pair<int, int>> tree;
  vector<int> ve;
  int n;

  cin >> n;
  for(int i = 0; i < n; i++) {
    int p, h;
    cin >> p >> h;
    ve.push_back(p);
    ve.push_back(p - h);
    ve.push_back(p + h);
    tree.emplace_back(p, h);
  }
  sort(tree.begin(), tree.end());
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  for(int i = 0; i < (int)ve.size(); i++) {
    mp[ve[i]] = i;
  }
  vector<int> dp((int)ve.size(), -INF);
  for(int i = 0; i < n; i++) {
    int height = tree[i].second, pos = tree[i].first;
    dp[mp[pos + height]] = max(dp[mp[pos + height]], height);
    if(dp[mp[pos]] > 0)
      dp[mp[pos + height]] = max(dp[mp[pos + height]], height + dp[mp[pos]]);
    dp[mp[pos]] = max(dp[mp[pos]], height);
    if(dp[mp[pos - height]] > 0)
      dp[mp[pos]] = max(dp[mp[pos]], dp[mp[pos - height]] + height);
  }
  int ans = -INF;
  for(int i = 0; i < n; i++) {
    int height = tree[i].second, pos = tree[i].first;
    ans = max(ans, dp[mp[pos]]);
    ans = max(ans, dp[mp[pos + height]]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}