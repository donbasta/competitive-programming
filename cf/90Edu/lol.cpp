#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  for(int i = 1; i <= n; i++) {
    cur.emplace((int)adj[i].size(), i);
  }
  while(!cur.empty()) {
    auto top = *cur.begin();
    cur.erase(top);
    int node = top.second;
    for(auto i : adj[node]) {
      cur.erase(make_pair((int)adj[i].size()))
      for(auto k : adj[i]) {

      }
    }
  }

  return 0;
}
