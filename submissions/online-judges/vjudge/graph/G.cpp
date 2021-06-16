#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
bool ok = 1;

vector<vector<int>> adj;
set<int> se;
vector<int> low, tin;
vector<bool> vis;
int timer;

void dfs(int v, int p) {
  vis[v] = 1;
  tin[v] = low[v] = timer++;
  int ch = 0;
  for(int to : adj[v]) {
    if(to == p) continue;
    if(vis[to]) { low[v] = min(low[v], tin[to]); }
    else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if(low[to] >= tin[v] && p != -1) { se.insert(v); }
      ++ch;
    }
  }
  if(p == -1 && ch > 1) { se.insert(v); }
}

void init() {
  timer = 0;
  adj.clear();
  adj.resize(n + 1);
  se.clear();
  low.assign(n + 1, -1);
  tin.assign(n + 1, -1);
  vis.assign(n + 1, 0);
}

void solve() {
  cin >> n >> m;
  if(n == 0 && m == 0) { ok = 0; return; }

  init();

  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  cout << (int)se.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  while(ok) { solve(); }
  
  return 0;
}