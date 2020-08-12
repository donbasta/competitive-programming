#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ve(n);
  vector<bool> vis(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> ve[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(vis[i]) continue;
    vis[i] = true;
    int next = ve[i] - 1;
    int cnt = 0;
    while(!vis[next]) {
      vis[next] = true;
      cnt++;
      next = ve[next] - 1;
    }
    ans += cnt;
  }
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