#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> m;

  //init dengan INF dulu;

  for(int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    ll pos = getPos(x, y, z);
    blocked[pos] = 0;
  }
  cin >> xr >> yr >> zr;
  initLoc = getPos(xr, yr, zr);
  cin >> xk >> yk >> zk;
  dest = getPos(xk, yk, zk);
  queue<pair<int, tuple<int, int, int>>> Q;
  Q.emplace(0, make_tuple(xr, yr, zr));
  while(!Q.empty()) {
    auto now = *se.begin();
    se.erase(se.begin());
    vector<tuple<int, int, int>> can = getNext(now.second);
    for(auto next : can) {
      if(blocked.find(getPos(next)) != blocked.end()) continue;
      if(dist[])
    }
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