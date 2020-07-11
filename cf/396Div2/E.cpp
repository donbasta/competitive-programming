#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e5 + 69;

int n;
int ar[N];
vector<int> adj[N], bit;
ll ans;
ll dp[N][2], depe[N];

void dfs(int node, int par = 0) {
  if(bit[node] == 1) {
    dp[node][1] = 1;
    depe[node]++;
    vector<ll> temp(2);
    for(auto child : adj[node]) {
      if(child == par)
        continue;
      dfs(child, node);
      for(int i = 0; i < 2; i++) {
        dp[node][i] += dp[child][i ^ 1];
        temp[i] += dp[child][i] * dp[child][i];
      }
      depe[node] += depe[child];
    }
    ll cur = 0;
    for(int i = 0; i < 2; i++) {
      ll tmp = (dp[node][i ^ 1] * dp[node][i ^ 1]) - temp[i];
      cur += tmp / 2;
    }
    depe[node] += cur;
  } else if(bit[node] == 0) {
    dp[node][0] = 1;
    ll temp = 0;
    for(auto child : adj[node]) {
      if(child == par)
        continue;
      dfs(child, node);
      for(int i = 0; i < 2; i++) {
        dp[node][i] += dp[child][i];
      }
      temp += dp[child][0] * dp[child][1];
      depe[node] += depe[child];
    }
    ll cur = 0;
    cur = dp[node][0] * dp[node][1] - temp;
    depe[node] += cur;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i < 22; i++) {
    memset(dp, 0, sizeof(dp));
    memset(depe, 0, sizeof(depe));
    bit.clear();
    bit.resize(n + 1);
    bool ok = true;
    for(int j = 1; j <= n; j++) {
      bit[j] = (ar[j] >> i) & 1;
      ok &= (!bit[j]);
    }
    if(ok)
      continue;
    dfs(1);
    ans += (1LL << i) * depe[1];
  }
  cout << ans << '\n';
  return 0;
}