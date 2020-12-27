#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  ll sisa = n % m;
  if (sisa == 0) {
    cout << 0;
  } else {
    ll ans = min(sisa * b, (m - sisa) * a);
    cout << ans;
  }
  cout << '\n';
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