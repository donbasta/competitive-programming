#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct FlowEdge {
  int v, u;
  ll cap, flow = 0;
  FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
  const ll flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }

  void add_edge(int v, int u, ll cap = 1) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      for(int id : adj[v]) {
        if(edges[id].cap - edges[id].flow < 1) { continue; }
        if(level[edges[id].u] != -1) { continue; }
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  ll dfs(int v, ll pushed) {
    if(pushed == 0) { return 0; }
    if(v == t) { return pushed; }
    for(int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) { continue; }
      ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if(tr == 0) { continue; }
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  ll flow() {
    ll f = 0;
    while(1) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if(!bfs()) { break; }
      fill(ptr.begin(), ptr.end(), 0);
      while(ll pushed = dfs(s, flow_inf)) { f += pushed; }
    }
    return f;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  Dinic mf = Dinic(n + m + 2, 0, n + m + 1);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for(int j = 2; j * j <= x; j++) {
      if(x % j == 0) {
        if(j <= m) { mf.add_edge(i, n + j); }
        while(x % j == 0) { x /= j; }
      }
    }
    if(x > 1) { if(x <= m) { mf.add_edge(i, n + x); } }
  }
  for(int i = 1; i <= n; i++) { mf.add_edge(0, i); }
  for(int i = 1; i <= m; i++) { mf.add_edge(n + i, n + m + 1); }
  ll ans = mf.flow();
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