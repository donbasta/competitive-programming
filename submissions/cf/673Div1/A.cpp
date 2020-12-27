#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> pos(n + 1), mn(n + 1, 0);
  vector<bool> ok(n + 1, 1), ada(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ada[x] = 1;
    mn[x] = max(i - pos[x], mn[x]);
    pos[x] = i;
  }
  for(int i = 1; i <= n; i++) {
    mn[i] = max(mn[i], n + 1 - pos[i]);
  }
  int ans = -1;
  for(int i = 1; i <= n; i++) {
    
  }
  for(int i = 1; i <= n; i++) {
    if(ok[i] && ada[i]) {
      ans = i;
      break;
    }
  }
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