#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll ceil(ll a, ll b) {
  return (a + b - 1) / b;
}

void solve() {
  ll x, y, k;
  cin >> x >> y >> k;
  ll p = ceil(y * k + k - 1, x - 1);
  ll ans = p + k;
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