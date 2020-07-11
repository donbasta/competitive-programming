#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int m, n, timer, l;
int tin[N], depth[N], sz[N];
vector<int> tua, ve[N], up[N], adj[N];


void dfs(int node, int par = 0) {
  tin[node] = ++timer;
  up[node][0] = par;
  depth[node] = depth[par] + 1;
  sz[node] = 1;
  ve[depth[node]].push_back(tin[node]);
  for(int i = 1; i <= l; i++) {
    up[node][i] = up[up[node][i - 1]][i - 1];
  }
  for(int child : adj[node]) {
    if(child == par)
      continue;
    dfs(child, node);
    sz[node] += sz[child];
  }
}

bool isAncestor(int u, int v) {
  return (tin[u] <= tin[v]) && (tin[v] < tin[u] + sz[u]);
}

int lca(int u, int v) {
  if(isAncestor(u, v))
    return u;
  if(isAncestor(v, u)) 
    return v;
  for(int i = l; i >= 0; i--) {
    if(!isAncestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

int kth(int u, int k) {
  int cur = u;
  for(int i = l; i >= 0; i--) {
    if(k & (1 << i))
      cur = up[cur][i];
  }
  return cur;
}

void prep() {
  l = ceil(log2(n));
  for(int i = 0; i <= n; i++)
    up[i].resize(l + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  // cout << n;
  for(int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    if(r == 0){
      tua.push_back(i);
      continue;
    }
    adj[r].push_back(i);
    adj[i].push_back(r);
  }
  prep();
  for(auto i : tua)
    dfs(i);
  // cerr << "lol";
  cin >> m;
  while(m--) {
    int v, p;
    cin >> v >> p;
    int gen = depth[v];
    if(p >= gen) {
      cout << 0 << ' ';
      continue;
    }
    int kakek = kth(v, p);
    int b1 = lower_bound(ve[gen].begin(), ve[gen].end(), tin[kakek] + sz[kakek]) - ve[gen].begin();
    int b2 = lower_bound(ve[gen].begin(), ve[gen].end(), tin[kakek]) - ve[gen].begin();
    cout << b1 - b2 - 1 << ' ';
    // cout << ' ' << b1 - b2 - 1 << ' ' << b1 << ' ' << b2 << '\n';
  }
  cout << '\n';
  return 0;
}
