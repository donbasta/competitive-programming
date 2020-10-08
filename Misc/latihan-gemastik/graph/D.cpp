#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

vector<int> adj[N + 5];
bool vis[N + 5];
bool ok = 1;
int col[N + 5];

void bfs(int v) {
  queue<int> Q;
  Q.emplace(v);
  vis[v] = 1;
  while(!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for(auto i : adj[cur]) {
      if(vis[i]) {
        if(col[cur] == col[i]) {
          ok = 0; break;
        }
        continue;
      }
      vis[i] = 1;
      col[i] = col[cur] ^ 1;
      Q.emplace(i);
    }
  }
}

int n, m;

inline void solve() {
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    bfs(i);
  }
  if(!ok) {
    cout << -1 << '\n';
    return;
  }

  vector<int> ve[2];
  for(int i = 1; i <= n; i++) {
    ve[col[i]].push_back(i);
  }
  for(int i = 0; i < 2; i++) {
    cout << (int)ve[i].size() << '\n';
    for(auto j : ve[i]) {
      cout << j << ' ';
    }
    cout << '\n';
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