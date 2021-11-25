#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct graph
{
  int n;
  vector<vector<int>> adj;
  graph(int n) : n(n), adj(n) {}
  void add_edge(int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int>& operator[](int u) { return adj[u]; }
};
 
vector<vector<int>> biconnected_components(graph &adj){
  int n = adj.n;
  vector<int> num(n), low(n), art(n), stk;
  vector<vector<int>> comps;
  function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
  {
    num[u] = low[u] = ++t;
    stk.push_back(u);
    for (int v : adj[u]) if (v != p){
      if (!num[v]){
        dfs(v, u, t);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[u]){
          art[u] = (num[u] > 1 || num[v] > 2);
 
          comps.push_back({u});
          while (comps.back().back() != v)
            comps.back().push_back(stk.back()), stk.pop_back();
        }
      }
      else low[u] = min(low[u], num[v]);
    }
  };
 
  for (int u = 0, t; u < n; ++u)
    if (!num[u]) dfs(u, -1, t = 0);
 
  // build the block cut tree
  function<graph()> build_tree = [&](){
    graph tree(0);
    vector<int> id(n);
    for (int u = 0; u < n; ++u)
      if (art[u]) id[u] = tree.add_node();
    for (auto &comp : comps) {
      int node = tree.add_node();
      for (int u : comp)
        if (!art[u]) id[u] = node;
        else tree.add_edge(node, id[u]);
    }
    return tree;
  };
 
  return comps;
}

void solve() {
  cin >> n >> m;
  // vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      // edges[i] = make_pair(u, v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
  }

  cin >> q;
  while (q--){
      int a, b;
      cin >> a >> b;
      
      if (dist[a][b] >= INF){
          cout << 2 << '\n';
          continue;
      }

      if (comp[a] == comp[b]){
          cout << 2 << '\n';
          continue;
      }

      int ans = dist[a][b] + 2;
      cout << ans << '\n';
  }
  return 0;
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


