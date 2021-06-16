#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e3 + 69;
const ll MOD = 1e9 + 7;

ll dp[N][N];
ll ans[N];
vector<pair<ll, ll>> adj[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> m >> q;
  for(int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  for(auto i : adj[1])
    dp[1][i.first] = i.second;

  for(int i = 2; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(dp[i - 1][j] == 0)
        continue;
      for(auto k : adj[j]) {
        dp[i][k.first] = max(dp[i][k.first], dp[i - 1][j] + k.second);
      }
    }
  }

  int a, b;
  a = b = 1;
  bool ok = false;
  for(int i = 1; i <= m; i++) {
    ans[i] = 0;
    for(int j = 1; j <= n; j++) {
      if(dp[i][j] > ans[i]){
        ans[i] = dp[i][j];
        pos[i] = j;
      }
    }
    if(last[pos[i]] != 0 && !ok) {
      a = last[pos[i]];
      b = i;
      ok = true;
    } else {
      last[pos[i]] = i;
    }
  }

  for(int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + ans[i] % MOD;
  }

  int t = m % (b - a);
  ll ans = 








  return 0;
}
