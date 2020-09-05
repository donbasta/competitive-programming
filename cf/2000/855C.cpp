#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
const int X = 10;
const int MOD = 1e9 + 7;

int n, m, k, x;
vector<int> adj[N + 1];
int dp[N + 1][X + 1][3] //node, banyak highest, state root

void dfs(int v, int p) {
  for(auto c : adj[v]) {
    if(c == p) continue;
    dfs(c, v);
    

  }

}

void solve() {
  cin >> n >> m;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> k >> x;
  dfs(1, 0);
  ll ans = 0;
  for(int i = 0; i <= x; i++) {
    ans = ans + dp[1][i][0] % MOD;
    ans = ans + dp[1][i][1] % MOD;
  }
  if(ans < 0) ans += MOD;
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