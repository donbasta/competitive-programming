#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int m, n;
vector<ll> p, cnt, cntz, we;
vector<vector<int>> adj;

void dfs(int v, int p) {
  cnt[v] = 1;
  for(auto& c : adj[v]) {
    if(c == p) continue;
    dfs(c, v);
    cnt[v] += cnt[c];
  }
}

void init() {
  adj.assign(n + 1, vector<int>());
  we.assign(n - 1, 1);
  cnt.assign(n + 1, 0);
  cntz.clear();
}

void solve() {
  cin >> n;
  init();
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> m;
  p.assign(m, 0);
  for(int i = 0; i < m; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end(), greater<ll>());
  if(m <= n - 1) {
    for(int i = 0; i < m; i++) {
      we[i] = p[i];
    }
  } else {
    ll temp = 1;
    for(int i = 0; i < m - (n - 2); i++) {
      temp = 1LL * temp * p[i] % MOD;
    }
    we[0] = temp;
    for(int i = 1; i < n - 1; i++) {
      we[i] = p[i + m - n + 1] % MOD;
    }
  }
  dfs(1, 0);
  for(int i = 2; i <= n; i++) {
    ll cur = 1LL * cnt[i] * (n - cnt[i]);
    cntz.push_back(cur);
  }
  sort(cntz.begin(), cntz.end(), greater<ll>());
  ll ans = 0;
  for(int i = 0; i < n - 1; i++) {
    cntz[i] %= MOD;
    ans = (ans + cntz[i] * we[i]) % MOD;
  }
  if(ans < 0) ans += MOD;
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