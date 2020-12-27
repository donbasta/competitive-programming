#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pii pair<int, int>

const int N = 2e5 + 5;

pii adj[N];
int out[N];
bool can[N];
int dis[N];

void dfs(int v, int p)

void solve() {
  cin >> n >> m >> t;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[z].emplace_back(x, y);
    out[z]++;
  }

  for (int i = 1; i <= n; i++) {
    se.emplace(out[i], i);
  }

  cin >> k;
  for (int i = 1; i <= k; i++) {
    int s;
    cin >> s;
    can[s] = 1;
  }

  while(!se.empty()) {
    auto t = *se.begin();
    assert(t.first == 0);
    se.erase(se.begin());
    if (!can[t.second]) continue;
    for (auto& elem : pre[t.second]) {
      
    }
  }

  
  cout << val[t] << '\n';
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