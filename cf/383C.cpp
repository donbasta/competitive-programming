#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 69;

int ar[N], sz[N], tin[N], as[N];
bool dep[N];
vector<int> adj[N];
int timer, n, m;
int seg[4 * N];

void dfs(int node, int par = 0) {
  tin[node] = ++timer;
  sz[node] = 1;
  dep[node] = !dep[par];
  for(auto i : adj[node]) {
    if(i == par)
      continue;
    dfs(i, node);
    sz[node] += sz[i];
  }
}

void build(int v, int tl, int tr) {
  if(tl == tr) {
    seg[v] = as[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(v << 1, tl, tm);
  build((v << 1) | 1, tm + 1, tr);
}

void upd(int v, int tl, int tr, int l, int r, int val) {
  if(l > r)
    return;
  if(l <= tl && r >= tr) {
    seg[v] += val;
    return;
  }
  int tm = (tl + tr) / 2;
  upd(v << 1, tl, tm, l, min(r, tm), val);
  upd((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, val);
}

int que(int v, int tl, int tr, int pos) {
  if(tl == tr) 
    return seg[v];
  int tm = (tl + tr) / 2;
  if(pos <= tm)
    return seg[v] + que(v << 1, tl, tm, pos);
  else 
    return seg[v] + que((v << 1) | 1, tm + 1, tr, pos);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[0] = 1;
  dfs(1);
  for(int i = 1; i <= n; i++) {
    as[tin[i]] = (dep[i] ? -ar[i] : ar[i]);
  }
  build(1, 1, n);
  while(m--) {
    int q, x, val;
    cin >> q;
    if(q == 1) {
      cin >> x >> val;
      if(dep[x])
        val = -val;
      upd(1, 1, n, tin[x], tin[x] + sz[x] - 1, val);
    } else if(q == 2) {
      cin >> x;
      int ans = que(1, 1, n, tin[x]);
      cout << (dep[x] ? -ans : ans) << '\n';
    }
  }
  return 0;
}
