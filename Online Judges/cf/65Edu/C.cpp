#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

int idx = 0;
int n, m;
vector<int> adj[N+5];
int par[N+5], sz[N+5];

void dfs(int v) {
  par[v] = idx;
  if (v < n) sz[idx]++;
  for (auto& c : adj[v]) {
    if (par[c] == -1) dfs(c);
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int l;
      cin >> l;
      --l;
      adj[l].push_back(i + n);
      adj[i + n].push_back(l);
    }
  }

  memset(par, -1, sizeof(par));
  for (int i = 0; i < n; i++) {
    if (par[i] == -1) {
      idx++;
      dfs(i);
    }
  } 
  for (int i = 0; i < n; i++) {
    // cerr << par[i] << ' ';
    cout << sz[par[i]] << ' ';
  }
  cout << '\n';
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