#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m, mn, mx, cnt, ans;
vector<pair<int, int>> ve;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    ve.emplace_back(l, r);
  }
  sort(ve.begin(), ve.end());
  mn = ve[0].first, mx = ve[0].second, cnt = 1;
  for(int i = 1; i < n; i++) {
    if(ve[i].first <= mx) {
      mx = max(ve[i].second, mx);
      cnt++;
    } else {
      ans += max(0, cnt - (mx - mn + 1));
      mn = ve[i].first, mx = ve[i].second, cnt = 1;
    }
  }
  ans += max(0, cnt - (mx - mn + 1));
  cout << ans << '\n';
  return 0;
}