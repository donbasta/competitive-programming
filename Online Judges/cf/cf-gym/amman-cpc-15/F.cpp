#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
int ans, t;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<int> tin, low;

void dfs(int v, int p) {
  vis[v] = true;
  tin[v] = low[v] = t++;
  for(auto to : adj[v]) {
    if(to.first == p) continue;
    if(vis[to.first]) {
      low[v] = min(low[v], tin[to.first]);
    } else {
      dfs(to.first, v);
      low[v] = min(low[v], low[to.first]);
      if(low[to.first] > tin[v]) {
        ans = max(ans, to.second);
      }
    }
  }
}

void init() {
  t = 0;
  adj.assign(n + 1, vector<pair<int, int>>());
  vis.assign(n + 1, false);
  tin.assign(n + 1, -1);
  low.assign(n + 1, -1);
  ans = -1;
}

void solve() {
  cin >> n >> m;
  init();
  for(int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    adj[x].emplace_back(y, c);
    adj[y].emplace_back(x, c);
  }
  dfs(1, 0);
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