#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int ma = 2e9, mb = 2e9;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    ma = min(a[i], ma);
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    mb = min(b[i], mb);
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += max(a[i] - ma, b[i] - mb);
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