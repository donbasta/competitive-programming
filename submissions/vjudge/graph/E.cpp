#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

bool vis[N + 5];
bool ada[N + 5][N + 5];
int dis[N + 5][2];
vector<int> adj[N + 5];

void bfs(int v, int idx) {
  queue<int> Q;
  Q.emplace(v);
  vis[v] = 1;
  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for(auto i : adj[cur]) {
      if(vis[i]) continue;
      vis[i] = 1;
      dis[i][idx] = dis[cur][idx] + 1;
      Q.emplace(i);
    }
  }
}

void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ada[u][v] = ada[v][u] = 1;
  }
  bfs(s, 0);
  fill(vis + 1, vis + n + 1, 0);
  bfs(t, 1);
  assert(dis[t][0] == dis[s][1]);

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(ada[i][j]) continue;
      int mn = dis[i][0] + dis[j][1] + 1;
      mn = min(mn, dis[i][1] + dis[j][0] + 1);
      if(mn >= dis[s][1]) ans++;
    }
  }
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