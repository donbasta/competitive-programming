#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 20;

set<int> adj[M];
bool vis[M];

int dfs(int v) {
  int ret = 1;
  vis[v] = true;
  for(auto i : adj[v]) {
    if(vis[v]) continue;
    ret += dfs(i);
  }
  return ret;
}

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  bool ok = true;
  for(int i = 0; i < n; i++) {
    ok &= (a[i] <= b[i]);
  }
  if(!ok) {
    cout << -1 << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
    // cerr << a[i] << ' ' << b[i] << '\n';
    int x = a[i] - 'a';
    int y = b[i] - 'a';
    cerr << i << ' ' << x << ' ' << y << '\n';
    adj[x].insert(y);
    adj[y].insert(x);
  }
  int ans = 0;
  for(int i = 0; i < 20; i++) {
    cerr << i << ' ' << dfs(i) << '\n';
    // if(!vis[i]) ans += (dfs(i) - 1);
  }
  cout << ans << '\n';
  for(int i = 0; i < 20; i++) adj[i].clear();
  memset(vis, 0, sizeof(vis));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}