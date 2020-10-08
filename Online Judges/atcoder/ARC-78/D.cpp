#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5 + 10;

vector<int> adj[N];
int dis[N], par[N];
bool vis[N];
int n;

int dfs(int v, int par) {
  int ret = 1;
  for(auto i : adj[v]) {
    if(i == par) continue;
    ret += dfs(i, v);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  queue<int> Q;
  Q.push(1);
  dis[1] = 0;
  vis[1] = true;
  bool ok = false;
  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for(auto i : adj[cur]) {
      if(vis[i]) continue;
      vis[i] = true;
      par[i] = cur;
      dis[i] = dis[cur] + 1;
      if(i == n) {
        ok = true;
        break;
      }
      Q.push(i);
    }
    if(ok) break;
  }
  int lol = dis[n];
  int now = n;
  while(dis[now] != (lol / 2 + 1)) {
    now = par[now];
  }
  int cnt = dfs(now, par[now]);
  bool yes = ((cnt == n / 2 && (n % 2 == 0)) || cnt > n / 2);
  cout << (yes ? "Snuke" : "Fennec") << '\n';
  return 0;
}