#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

vector<int> adj[N + 5];
bool vis[N + 5], ada[N + 5];

void dfs(int v) {
  vis[v] = 1;
  for(auto c : adj[v]) {
    if(vis[c]) continue;
    dfs(c);
  }
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  for(int i = 1; i <= b; i++) {
    int x, y;
    cin >> x >> y;
    ada[x] = 1;
    adj[x].push_back(y);
  }
  for(int i = 1; i <= n; i++) {
    if(ada[i]) continue;
    if(i > 1) adj[i].push_back(i - 1);
    if(i < n) adj[i].push_back(i + 1);
  }
  dfs(1);
  cout << (vis[a] ? "YES" : "NO") << '\n';
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