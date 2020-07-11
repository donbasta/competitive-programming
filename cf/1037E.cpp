#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 5;

int n, m, k;
vector<pair<int, int>> edge;
set<int> adj[N];
bool gone[N];
vector<int> res;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    edge.emplace_back(x, y);
    adj[x].emplace(y);
    adj[y].emplace(x);
  }
  set<pair<int, int>> deg;
  for(int i = 1; i <= n; i++) {
    deg.emplace((int)adj[i].size(), i);
  }
  for(int i = m - 1; i >= 0; i--) {
    while(!deg.empty() && ((deg.begin())->first < k)) {
      auto cur = *deg.begin();
      deg.erase(deg.begin());
      int del = cur.second;
      gone[del] = true;
      for(auto j : adj[del]) {
        if(gone[j])
          continue;
        deg.erase(make_pair((int)adj[j].size(), j));
        adj[j].erase(del);
        deg.emplace((int)adj[j].size(), j);
      }
    }
    res.emplace_back((int) deg.size());
    auto now = edge[i];
    int a = now.first, b = now.second;
    if(!gone[a]) {
      deg.erase(make_pair((int)adj[a].size(), a));
      adj[a].erase(b);
      deg.emplace((int)adj[a].size(), a);
    }
    if(!gone[b]) {
      deg.erase(make_pair((int)adj[b].size(), b));
      adj[b].erase(a);
      deg.emplace((int)adj[b].size(), b);
    }
  }
  reverse(res.begin(), res.end());
  for(auto i : res) {
    cout << i << '\n';
  }
  return 0;
}
