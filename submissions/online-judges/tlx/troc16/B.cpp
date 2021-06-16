#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> ve(n);
  for (int i = 0; i < n; i++) {
    cin >> ve[i];
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  int sz = (int) ve.size();
  if (sz == 1) {
    cout << 0 << '\n';
    return;
  }
  int mx = -1;
  for (int i = 0; i < sz; i++) {
    int ni = (i + 1) % sz;
    int dif = ve[ni] - ve[i];
    if (dif < 0) dif += m;
    mx = max(dif, mx);
  }
  int ans = m - mx;
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