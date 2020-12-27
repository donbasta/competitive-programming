#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> m >> x >> k >> y;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  int cur = 0;
  vector<int> pos(1, -1);
  for(int i = 0; i < m; i++) {
    while(cur < n && a[cur] != b[i]) {
      cur++;
    }
    if(cur == n) break;
    pos.push_back(cur);
  }
  pos.push_back(m);
  if((int)pos.size() < m + 2) {
    cout << -1 << '\n'; return;
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}