#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct FlowEdge {
  int v, u;
  long long cap, flow = 0;
  FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
  const long long flow_inf = 1e18;
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

  void add_edge(int v, int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].u] != -1)
          continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  long long dfs(int v, long long pushed) {
    if (pushed == 0)
      return 0;
    if (v == t)
      return pushed;
    for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  long long flow() {
    long long f = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
        break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)) {
        f += pushed;
      }
    }
    return f;
  }
};

const ll INF = 1e18;
const int N = 100;
int n, e;
ll x;
ll p[N + 5], q[N + 5];
vector<pair<int, int>> adj[N + 5];

inline void solve() {
  cin >> n >> e >> x;
  ll tot = 0;
  for(int i = 1; i <= n; i++) {
    cin >> q[i];
    tot += q[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  Dinic mcmf = Dinic(n + 2, 0, n + 1);
  for(int i = 1; i <= n; i++) {
    mcmf.add_edge(0, i, q[i]);
    mcmf.add_edge(i, n + 1, p[i]);
  }
  for(int i = 1; i <= e; i++) {
    int ki, kj; 
    ll ti;
    cin >> ki >> kj >> ti;
    adj[ki].emplace_back(kj, ti);
    adj[kj].emplace_back(ki, ti);
  }
  for(int i = 1; i <= n; i++) {
    set<pair<int, ll>> se;
    vector<ll> dis(n + 1, INF);
    vector<bool> vis(n + 1);
    se.emplace(i, 0);
    dis[i] = 0;
    while(!se.empty()) {
      auto now = *se.begin();
      se.erase(se.begin());
      if(vis[now.first]) { continue; }
      vis[now.first] = 1;
      for(auto to : adj[now.first]) {
        if(dis[now.first] + to.second < dis[to.first]) {
          dis[to.first] = dis[now.first] + to.second;
          se.emplace(to.first, dis[to.first]);
        }
      }
    }
    for(int j = 1; j <= n; j++) {
      if(j == i) continue;
      if(dis[j] > x) continue;
      mcmf.add_edge(i, j, INF);
    }
  }
  ll not_die = mcmf.flow();
  cout << tot - not_die << '\n';
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