#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
vector<int> par, sz;
vector<pair<int, pair<int, int>>> edges;

int fpar(int a) {
  return (a == par[a] ? a : par[a] = fpar(par[a]));
}

void merge(int a, int b) {
  int pa = fpar(a);
  int pb = fpar(b);
  if(pa == pb) return;
  if(sz[pa] < sz[pb]) swap(pa, pb);
  sz[pa] += sz[pb];
  par[pb] = pa;
}

void init() {
  edges.clear();
  par.assign(n + 1, 0);
  sz.assign(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    par[i] = i, sz[i] = 1;
  }
}

void solve() {
  cin >> n >> m;
  init();
  for(int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    edges.emplace_back(c, make_pair(x, y));
  }
  sort(edges.begin(), edges.end());
  int cnt = 0;
  int ans = -1;
  for(int i = 0; i < m; i++) {
    if(cnt == n - 1) break;
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    if(fpar(a) == fpar(b)) continue;
    merge(a, b);
    cnt++;
    ans = max(ans, edges[i].first);
  }
  cout << ans << '\n';
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