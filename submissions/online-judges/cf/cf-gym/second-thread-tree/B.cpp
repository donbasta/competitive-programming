#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 3e5;

int n;
vector<int> adj[N + 5];
int dis[2][N + 5];

int find_diameter() {
  queue<int> q;
  vector<int> dis_temp(n + 1);
  vector<bool> vis(n + 1);

  q.emplace(1);
  vis[1] = 1;

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto i : adj[cur]) {
      if(vis[i]) continue;
      vis[i] = 1;
      q.emplace(i);
      dis_temp[i] = dis_temp[cur] + 1;
    }
  }

  int idx = 1, mx = 0;
  for(int i = 1; i <= n; i++) {
    if(dis_temp[i] > mx) {
      mx = dis_temp[i];
      idx = i;
    }
  }

  vis.clear(), vis.resize(n + 1);

  q.emplace(idx);
  vis[idx] = 1; 
  dis[0][idx] = 0;

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto i : adj[cur]) {
      if(vis[i]) continue;
      vis[i] = 1;
      q.emplace(i);
      dis[0][i] = dis[0][cur] + 1;
    }
  }

  mx = 0;
  int idx2 = 1;
  for(int i = 1; i <= n; i++) {
    if(i == idx) continue;
    if(dis[0][i] > mx) {
      mx = dis[0][i];
      idx2 = i;
    }
  }

  vis.clear(), vis.resize(n + 1);

  q.emplace(idx2);
  vis[idx2] = 1; 
  dis[1][idx2] = 0;

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto i : adj[cur]) {
      if(vis[i]) continue;
      vis[i] = 1;
      q.emplace(i);
      dis[1][i] = dis[1][cur] + 1;
    }
  }

  return mx;
}

void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int diam = find_diameter();
  for(int i = 1; i <= n; i++) {
    int ans = max({diam, dis[0][i] + 1, dis[1][i] + 1});
    cout << ans << '\n';
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