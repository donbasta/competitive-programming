#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n;
int a[N + 5], b[N + 5], c[N + 5];
vector<int> adj[N + 5];
int cost[N + 5];
ll ans;
int st[N + 5][2];

void dfs_min(int v, int p) {
  for(auto ch : adj[v]) {
    if(ch == p) continue;
    cost[ch] = min(cost[v], a[ch]);
    dfs_min(ch, v);
  }
}

void dfs_isi(int v, int p) {
  st[v][0] = (b[v] == 0 && c[v] == 1);
  st[v][1] = (b[v] == 1 && c[v] == 0);
  for(auto ch : adj[v]) {
    if(ch == p) continue;
    dfs_isi(ch, v);
    st[v][0] += st[ch][0];
    st[v][1] += st[ch][1];
  }
  int mn = min(st[v][0], st[v][1]);
  ans += 1LL * cost[v] * 2 * mn;
  st[v][0] -= mn;
  st[v][1] -= mn;
}

void solve() {
  cin >> n;
  int cek = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    cek += (b[i] - c[i]);
  }
  if(cek) {
    cout << -1 << '\n';
    return;
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cost[1] = a[1];
  dfs_min(1, 1);
  dfs_isi(1, 1);
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