#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  ll sum = 0;
  int mx = -1;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mx = max(mx, t);
    sum += t;
  }
  ll ans = max(sum, 2LL * mx);
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