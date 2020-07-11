#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 4e5 + 69;

ll seg[N << 2];
bool mk[N << 2];
int tin[N], sz[N], ar[N], as[N];
vector<int> adj[N];
int timer, m, n;

void dfs(int node, int par = 0) {
  tin[node] = ++timer;
  sz[node] = 1;
  for(auto i : adj[node]) {
    if(i == par)
      continue;
    dfs(i, node);
    sz[node] += sz[i];
  }
}

void build(int v, int tl, int tr) {
  if(tl == tr) {
    seg[v] = (1LL << as[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  build(v << 1, tl, tm);
  build((v << 1) | 1, tm + 1, tr);
  seg[v] = seg[v << 1] | seg[(v << 1) | 1];
}

void push(int v) {
  if(!mk[v])
    return;
  seg[v << 1] = seg[(v << 1) | 1] = seg[v];
  mk[v << 1] = mk[(v << 1) | 1] = true;
  mk[v] = false;
}

void upd(int v, int tl, int tr, int l, int r, int col) {
  if(l > r)
    return;
  if(l == tl && r == tr){
    seg[v] = (1LL << col);
    mk[v] = true;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  upd(v << 1, tl, tm, l, min(r, tm), col);
  upd((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, col);
  seg[v] = seg[v << 1] | seg[(v << 1) | 1];
}

ll que(int v, int tl, int tr, int l, int r) {
  if(l > r)
    return 0;
  if(l <= tl && r >= tr)
    return seg[v];
  push(v);
  int tm = (tl + tr) / 2;
  ll a = que(v << 1, tl, tm, l, min(r, tm));
  ll b = que((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r);
  return a | b;
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
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  for(int i = 1; i <= n; i++)
    as[tin[i]] = ar[i];
  build(1, 1, n);
  while(m--) {
    int t, v, c;
    cin >> t;
    if(t == 1) {
      cin >> v >> c;
      upd(1, 1, n, tin[v], tin[v] + sz[v] - 1, c);
    } else if(t == 2) {
      cin >> v;
      ll mask = que(1, 1, n, tin[v], tin[v] + sz[v] - 1);
      cout << __builtin_popcountll(mask) << '\n';
    }
  }
  return 0;
}