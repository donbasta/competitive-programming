#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 1e5;
 
int n;
int a, b, da, db;
 
vector<int> adj[N + 5];
int dis[N + 5];
 
void dfs(int v, int p) {
  dis[v] = dis[p] + 1;
  for(auto c : adj[v]) {
    if(c == p) continue;
    dfs(c, v);
  }
}
 
void solve() {
  cin >> n;
  cin >> a >> b >> da >> db;
 
  for(int i = 1; i <= n; i++) { adj[i].clear(); }
 
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dis[0] = -1;
  dfs(a, 0);
  if(dis[b] <= da) {
    cout << "Alice" << '\n';
    return;
  }
  int mx = -1, idx = 0;
  for(int i = 1; i <= n; i++) {
    if(dis[i] > mx) {
      mx = dis[i], idx = i;
    }
  }
  dfs(idx, 0);
  int diameter = -1;
  for(int i =1; i <= n; i++) {
    diameter = max(diameter, dis[i]);
  }
  if(2 * da >= diameter) {
   cout << "Alice";
  } else if(db > 2 * da) {
   cout << "Bob";
  } else {
   cout << "Alice";
  }
  cout << '\n';
  return;
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}