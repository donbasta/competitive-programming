#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int LG = 20;

int n, m, lg, cur;
vector<int> adj[N], adjDec[N];

int timer;
int tin[N], tout[N], d[N], sz[N], par[N], ans[N], dp[N];
bool dead[N], col[N];
int up[N][LG];

void dfsLCA(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= lg; i++) {
    up[v][i] = up[up[v][i-1]][i-1];
  }
  for (auto c : adj[v]) {
    if (c != p) {
      d[c] = d[v] + 1;
      dfsLCA(c, v);
    }
  }
  tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v) {
  if (isAncestor(u, v)) return u;
  if (isAncestor(v, u)) return v;
  for (int i = lg; i >= 0; i--) {
    if (!isAncestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}

int dis(int u, int v) {
  return d[u] + d[v] - 2 * d[LCA(u, v)];
}

void dfsChild(int v, int p) {
  sz[v] = 1;
  for (auto c : adj[v]) {
    if (c == p || dead[c]) continue;
    dfsChild(c, v);
    sz[v] += sz[c];
  }
}

int dfsFindCentroid(int v, int p) {
  for (auto c : adj[v]) {
    if (c == p || dead[c]) continue;
    if (sz[c] > cur/2) return dfsFindCentroid(c, v);
  }
  return v;
}

void centroidDecomposition(int v, int p) {
  dfsChild(v, v);
  cur = sz[v];
  int ctr = dfsFindCentroid(v, v);
  par[ctr] = ((p == -1) ? ctr : p);
  // if (p != -1) {
  //   adjDec[p].push_back(ctr);
  // }
  dead[ctr] = 1;
  for (auto c : adj[ctr]) {
    if (dead[c]) continue;
    centroidDecomposition(c, ctr);
  }
  dead[ctr] = 0;
}

void init(int root) {
  lg = ceil(log2(n));
  dfsLCA(root, root);

  centroidDecomposition(root, -1);
  fill(ans, ans + N, INF);
  fill(dp, dp + N, INF);
}

// void dfsDec(int v) {
//   for (auto c : adj[v]) {
//     dp[v] = min(dp[v], )
//   }
// }

void upd(int u) {
  int tu = u;
  if (col[u]) {
    while (1) {
      // ans[tu] = min(ans[tu], dis(u, tu));
      ans[tu] = dp[tu];
      if (tu == par[tu]) break;
      tu = par[tu];
    }
  } else {
    while (1) {
      ans[tu] = min(ans[tu], dis(u, tu));
      if (tu == par[tu]) break;
      dp[par[tu]] = min(dp[par[tu]], ans[tu]);
      tu = par[tu];
    }
  }
  col[u] ^= 1;
}

int que(int u) {
  int tu = u;
  int ret = INF;
  while (1) {
    ret = min(ret, ans[tu] + dis(u, tu));
    if (tu == par[tu]) break;
    tu = par[tu];
  }
  return ret;
}

void solve() {
  cin >> n;

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  init(1);

  cin >> m;

  while (m--) {
    int t, v;
    cin >> t >> v;
    if (t == 0) {
      upd(v);
    } else {
      cout << que(v) << '\n';
    }
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