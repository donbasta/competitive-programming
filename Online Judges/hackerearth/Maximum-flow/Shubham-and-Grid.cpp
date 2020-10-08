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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
int cnt[4], pre[4], cur[4];
char c[25][25];
int pos[25][25];

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> c[i][j];
      cnt[c[i][j] - 'a']++;
    }
  }
  for(int i = 1; i < 4; i++) {
    pre[i] = pre[i - 1] + cnt[i - 1];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      pos[i][j] = cur[c[i][j] - 'a'] + pre[c[i][j] - 'a'];
      cur[c[i][j] - 'a']++;
    }
  }

  Dinic mcmf = Dinic(n * m + 2, 0, n * m + 1);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int id = pos[i][j];
      if(c[i][j] == 'a') { mcmf.add_edge(0, id, 1); }
      if(c[i][j] == 'd') { mcmf.add_edge(id, n * m + 1, 1); }
      for(int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if(c[ni][nj] - c[i][j] != 1) continue;
        int nid = pos[ni][nj];
        mcmf.add_edge(id, nid, 1);
      }
    }
  }

  ll ans = mcmf.flow();
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