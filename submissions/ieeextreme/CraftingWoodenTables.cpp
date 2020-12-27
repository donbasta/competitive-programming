#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll c,n,p,w;
  cin >> c >> n >> p >> w;
  ll ans;

  if (p > c) {
    ans = min(w/c, (p*n - w) / (p - c));
  } else {
    ans = w / c;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}