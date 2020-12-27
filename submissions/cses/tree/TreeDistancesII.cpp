#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

vector<int> adj[N + 5];
int cnt[N + 5];
ll sum[N + 5], ans[N + 5];
int n;

void dfs1(int v, int p) {
  cnt[v] = 1;
  for(auto c : adj[v]) {
    if(c == p) continue;
    dfs1(c, v);
    cnt[v] += cnt[c];
    sum[v] += (sum[c] + cnt[c]);
  }
}

void dfs2(int v, int p) {
  if(v != 1) ans[v] = ans[p] - 2 * cnt[v] + n;
  if(v == 1) ans[v] = sum[v];
  for(auto c : adj[v]) {
    if(c == p) continue;
    dfs2(c, v);
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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