#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 5e5 + 69;

bool seg[N << 2], mk[N << 2];
int n, q, timer;
int tin[N], sz[N], par[N];
vector<int> adj[N];

void dfs(int node, int pr = 0) {
  par[node] = pr;
  tin[node] = ++timer;
  sz[node] = 1;
  for(auto child : adj[node]) {
    if(child == pr)
      continue;
    dfs(child, node);
    sz[node] += sz[child];
  }
}

void build(int v, int tl, int tr) {
  if(tl == tr) {
    seg[v] = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(v << 1, tl, tm);
  build((v << 1) | 1, tm + 1, tr);
  seg[v] = 1;
}

void push(int v) {
  if(!mk[v])
    return;
  seg[v << 1] = seg[(v << 1) | 1] = seg[v];
  mk[v << 1] = mk[(v << 1) | 1] = true;
  mk[v] = false;
}

void upd(int v, int tl, int tr, int l, int r, bool val) {
  if(l > r)
    return;
  if(l == tl && r == tr){
    seg[v] = val;
    mk[v] = true;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  upd(v << 1, tl, tm, l, min(r, tm), val);
  upd((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, val);
  seg[v] = seg[v << 1] | seg[(v << 1) | 1];
}

bool que(int v, int tl, int tr, int l, int r) {
  if(l > r)
    return 0;
  if(l <= tl && r >= tr)
    return seg[v];
  push(v);
  int tm = (tl + tr) / 2;
  bool a = que(v << 1, tl, tm, l, min(r, tm));
  bool b = que((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r);
  return a | b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  build(1, 1, n);
  cin >> q;
  while(q--) {
    int c, v;
    cin >> c >> v;
    if(c == 1) {
      bool ok = que(1, 1, n, tin[v], tin[v] + sz[v] - 1);
      upd(1, 1, n, tin[v], tin[v] + sz[v] - 1, 0);
      if(ok && v > 1)
        upd(1, 1, n, tin[par[v]], tin[par[v]], 1);
    } else if(c == 2) {
      upd(1, 1, n, tin[v], tin[v], 1);
    } else if(c == 3) {  
      bool ada = que(1, 1, n, tin[v], tin[v] + sz[v] - 1);
      cout << (ada ? 0 : 1) << '\n';
    }
  }

  return 0;
}
