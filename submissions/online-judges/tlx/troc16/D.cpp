#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
vector<vector<pair<int, int>>> ve;
vector<int> p, sz;

void init() {
  for (int i = 0; i < 2 * n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}

int fpar(int a) {
  return (p[a] == a ? a : p[a] = fpar(p[a]));
}

void merge(int a, int b) {
  int pa = fpar(a);
  int pb = fpar(b);
  if (pa == pb) return;
  if (sz[pa] > sz[pb]) swap(pa, pb);
  p[pa] = pb;
  sz[pb] += sz[pa];
}

bool cek(int bat) {
  init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; ve[i][j].first < bat && j < n - 1; j++) {
      int tmn = ve[i][j].second;
      if (fpar(tmn) == fpar(i)) return false;
      merge(tmn, n + i);
      merge(i, n + tmn);
    }
  }
  int cek = sz[fpar(0)];
  if (cek == 2 * n) {
    return false;
  }
  return true;
}


void solve() {
  cin >> n;
  sz.resize(2 * n);
  p.resize(2 * n);
  ve.resize(n);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      ans = min(ans, x);
      if (i == j) continue;
      ve[i].emplace_back(x, j);
    }
    sort(ve[i].begin(), ve[i].end());
  }
  int l = 1, r = 1e9;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (cek(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
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