#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

vector<int> adj[N + 5];
bool vis[N + 5];

void dfs(int v) {
  vis[v] = true;
  for(auto c : adj[v]) {
    if(vis[c]) continue;
    dfs(c);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> ve;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      ve.push_back(i);
      dfs(i);
    }
  }
  cout << (int)ve.size() - 1 << '\n';
  for(int i = 0; i < (int)ve.size() - 1; i++) {
    cout << ve[i] << ' ' << ve[i + 1] << '\n';
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