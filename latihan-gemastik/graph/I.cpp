#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 1e5;

ll n, m, k;
bool tr[N + 5], vis[N + 5];
ll dis[N + 5];
vector<pair<ll, ll>> adj[N + 5];
set<pair<ll, ll>> se;

void dijkstra() {
  dis[1] = 0;
  se.emplace(dis[1], 1);
  while(!se.empty()) {
    auto cur = (se.begin())->second;
    se.erase(se.begin());
    if(vis[cur]) continue;
    vis[cur] = 1;
    for(auto i : adj[cur]) {
      ll a = i.first, b = i.second;
      if(tr[a] && dis[a] >= dis[cur] + b) { tr[a] = 0; }
      if(dis[a] > dis[cur] + b) {
        dis[a] = dis[cur] + b;
        se.emplace(dis[a], a);
      }
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    ll u, v, x;
    cin >> u >> v >> x;
    adj[u].emplace_back(v, x);
    adj[v].emplace_back(u, x);
  }
  fill(dis + 1, dis + 1 + n, INF);
  for(int i = 1; i <= k; i++) {
    ll s, y;
    cin >> s >> y;
    dis[s] = min(dis[s], y);
    se.emplace(dis[s], s);
    tr[s] = 1;
  }
  dijkstra();
  int ans = k;
  for(int i = 1; i <= n; i++) { ans -= (tr[i]); }
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