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

int n, m;
int hori, ver;
string gr[205];
int id[2][205][205];
int deg[2 * 200 * 199 + 5];

bool valid(int a, int b) {
  if(a >= 0 && a < n && b >= 0 && b < m) return gr[a][b] == '#';
  return 0;
}

void solve() {
  cin >> n >> m;
  ll bl = 0;
  for(int i = 0; i < n; i++) {
    cin >> gr[i];
    for(int j = 0; j < m - 1; j++) {
      bl += gr[i][j] == '#';
      if(gr[i][j] == '#' && gr[i][j + 1] == '#') { id[0][i][j] = ++hori; }
    }
    bl += gr[i][m - 1] == '#';
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < m; j++) {
      if(gr[i][j] == '#' && gr[i + 1][j] == '#') { id[1][i][j] = ++ver; }
    }
  }

  Dinic mcmf = Dinic(hori + ver + 2, 0, hori + ver + 1);

  for(int i = 1; i <= hori; i++) {
    mcmf.add_edge(0, i, 1);
  }
  for(int i = 1; i <= ver; i++) {
    mcmf.add_edge(hori + i, hori + ver + 1, 1);
  }

  int lol = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(gr[i][j] != '#') continue;
      vector<int> ud, lr;
      {
        int ni = i, nj = j + 1;
        if(valid(ni, nj)) lr.push_back(id[0][i][j]);
      }
      {
        int ni = i, nj = j - 1;       
        if(valid(ni, nj)) lr.push_back(id[0][i][j - 1]);
      }
      {
        int ni = i + 1, nj = j;
        if(valid(ni, nj)) ud.push_back(id[1][i][j]);
      }
      {
        int ni = i - 1, nj = j;
        if(valid(ni, nj)) ud.push_back(id[1][i - 1][j]);
      }
      for(auto ni : lr) {
        for(auto nj : ud) {
          deg[ni]++;
          deg[nj + hori]++;
          mcmf.add_edge(ni, nj + hori, 1);
        }
      }
    }
  }

  ll temp = mcmf.flow();
  cout << bl - (hori + ver - temp) << '\n';

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