#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
const int INF = 1e9;

struct DSU {
  int sz[N + 1], par[N + 1], val[N + 1];
  vector<int> ve[N + 1];
  void init(int a) {
    for(int i = 1; i <= a; i++) {
      sz[i] = 1, par[i] = i, val[i] = 0;
      ve[i].push_back(i);
    }
  }
  int fpar(int a) {
    return (a == par[a] ? par[a] : par[a] = fpar(par[a]));
  }
  void merge(int a, int b, int k) {
    int pa = fpar(a), pb = fpar(b);
    if(pa == pb) return;
    bool swapped = false;
    if(sz[pa] > sz[pb]) {swap(pa, pb), swapped = true;}
    sz[pb] += sz[pa];
    sz[pa] = 0;
    int dif;
    if(swapped) {
      dif = val[a] + k - val[b];
    } else {
      dif = val[b] - val[a] - k;
    }
    while(!ve[pa].empty()) {
      int cur = ve[pa].back();
      val[cur] += dif;
      ve[pb].push_back(cur);
      ve[pa].pop_back();
    }
    par[pa] = pb;
  }
} X, Y;

void solve() {
  int n, m;
  cin >> n >> m;
  X.init(n);
  Y.init(n);
  for(int i = 0; i < m; i++) {
    int a, b;
    int dx, dy;
    cin >> a >> b >> dx >> dy;
    X.merge(a, b, dx);
    Y.merge(a, b, dy);
  }
  for(int i = 1; i <= n; i++) {
    cout << X.val[i] << ' ' << Y.val[i] << '\n';
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