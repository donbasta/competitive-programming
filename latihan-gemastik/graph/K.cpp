#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;

void dfs(int v, vector<int>& nodes) {
  nodes.push_back(v);
  vis[v] = 1;
  for(auto i : adj[v]) {
    if(vis[i.first]) continue;
    dfs(i.first, nodes);
  }
}
 
vector<int> euler_tour(int src = 1) {
  vector<int> D(n + 1), its(n + 1), ret, s(1, src);
  map<int, bool> eu; 
  while(!s.empty()) {
    int x = s.back(), y, e, &it = its[x], end = (int)adj[x].size();
    if(it == end) { ret.push_back(x); s.pop_back(); continue; }
    tie(y, e) = adj[x][it++];
    if(!eu.count(e)) {
      D[x]--, D[y]++;
      eu[e] = 1; s.push_back(y);
    }
  }
  return {ret.rbegin(), ret.rend()};
}

void solve() {

  cin >> n >> m;

  adj.clear(), adj.resize(n + 1);
  vis.clear(), vis.resize(n + 1);
  vector<int> deg(n + 1);
  set<pair<int, int>> se;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
    deg[u]++, deg[v]++;
    if(u > v) swap(u, v);
    se.emplace(u, v);
  }
  int no = 0;
  vector<int> odd;
  for(int i = 1; i <= n; i++) {
    if(deg[i] & 1) { no++; odd.push_back(i); }
  }
  assert((int)odd.size() % 2 == 0);
  sort(odd.begin(), odd.end());
  int ext = m;
  int sz_odd = (int)odd.size();
  // cerr << sz_odd << '\n';
  vector<bool> udah(sz_odd, 0);
  for(int i = 0; i < sz_odd; i++) {
    if(udah[i]) continue;
    for(int j = i + 1; j < sz_odd; j++) {
      if(udah[j]) continue;
      if(!se.count(make_pair(odd[i], odd[j]))) {
        // cerr << odd[i] << ' ' << odd[j] << '\n';
        deg[odd[i]]++, deg[odd[j]]++;
        adj[odd[i]].emplace_back(odd[j], ext);
        adj[odd[j]].emplace_back(odd[i], ext++);
        udah[i] = udah[j] = 1;
        break;
      }
    }
  }
  cout << n - no << '\n';
  for(int i = 1; i <= n; i++) {
    if(vis[i]) continue;
    vector<int> temp;
    dfs(i, temp);
    vector<int> endpoints;
    for(auto j : temp) {
      if(deg[j] & 1) endpoints.push_back(j);
    }
    // cerr << (int)endpoints.size() << '\n';
    // for(auto i : endpoints) { cerr << i << " lol"; }
    // assert((int)endpoints.size() == 0 || (int)endpoints.size() == 2);
    int start = i;
    bool walk = 0;
    if(!endpoints.empty()) { start = endpoints[0]; walk = 1; }
    vector<int> order_tour = euler_tour(start);
    int sz = (int)order_tour.size();
    // for(auto i : order_tour) { cerr << i << ' '; } cerr << '\n';
    // if(walk) { assert(order_tour[sz - 1] == endpoints[1]); }
    for(int j = 0; j < sz; j++) {
      int nj = (j + 1) % (sz);
      int a = min(order_tour[j], order_tour[nj]);
      int b = max(order_tour[j], order_tour[nj]);
      if(!se.count(make_pair(a, b))) continue;
      cout << order_tour[j] << ' ' << order_tour[nj] << '\n';
      se.erase(make_pair(a, b));
    }
  }
  for(auto it : se) {
    cout << it.first << ' ' << it.second << '\n';
  }
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