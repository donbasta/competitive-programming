#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> mp;
  pair<int, int> ans = make_pair(INF, INF);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x == 0) continue;
    if(k % x == 0) {
      if(mp.find(k / x) != mp.end()) {
        int a = min(x, k / x);
        int b = max(x, k / x);
        ans = min(ans, make_pair(a, b));
      }
    } 
    mp[x]++;
  }
  if(ans == make_pair(INF, INF)) {
    cout << -1;
  } else {
    cout << ans.first << ' ' << ans.second;
  }
  cout << '\n';
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