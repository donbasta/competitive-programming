#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2005;

int n, cnt, idx = -1;
vector<bool> vis;
vector<int> adj[N][2];

void dfs(int v, int type) {
  vis[v] = true;
  cnt++;
  for(auto i : adj[v][type]) {
    if(vis[i])
      continue;
    dfs(i, type);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  vis.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if(x == 0) continue;
      if(i == j) {
        if(x > 0) 
          idx = i;
      }
      adj[i][0].push_back(j);
      adj[j][1].push_back(i);
    }
  }
  bool ok = true;
  for(int i = 0; i < 2; i++) {
    fill(vis.begin(), vis.end(), 0);
    cnt = 0;
    dfs(idx, i);
    ok &= (cnt == n);
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}
