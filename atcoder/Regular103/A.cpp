#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

map<int, int> mp[2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[i & 1][x]++;
  }
  int ans = 0;
  for(int i = 0; i < 2; i++) {
    int mx = 0;
    for(auto j : mp[i]) {
      mx = max(j.second, mx);
    }
    ans += mx;
  }
  ans = n - ans;
  cout << ans << '\n';
  return 0;
}
