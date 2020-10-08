#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<pair<int, int>> Ans;
 
void euler_tour(int src = 1) {
  vector<int> D(n + 1), its(n + 1), ret, s(1, src);
  vector<bool> eu(m); 
  int cnt = 0;
  while(cnt < m) {
    if(s.empty()) {
      for(int i = 1; i <= n; i++) {
        int temp = (int)adj[i].size();
        if((temp & 1 && its[i] < temp) || (temp % 2 == 0 && )) {
          cerr << i << "lol";
          s.push_back(i);
          break;
        }
      }
      continue;
    }
    int x = s.back(), y, e, &it = its[x], end = (int)adj[x].size();
    if(it == end || (D[x] == 1 && (end % 2 == 0))) { s.pop_back(); continue; }
    tie(y, e) = adj[x][it++];
    if(!eu[e]) {
      cnt++;
      D[x]++, D[y]--;
      Ans.emplace_back(x, y);
      eu[e] = 1; s.push_back(y);
    }
  }
}

void solve() {

  cin >> n >> m;

  adj.clear(), adj.resize(n + 1);
  vector<int> deg(n + 1);
  Ans.clear();

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
    deg[u]++, deg[v]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) { ans += (!(deg[i] & 1)); }
  cout << ans << '\n';
  euler_tour();
  for(auto i : Ans) {
    cout << i.first << ' ' << i.second << '\n';
  }

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