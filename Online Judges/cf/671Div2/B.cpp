#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ll f(ll t) { return (((1LL << (2 * t + 1)) - 2) / 3) - (1LL << t) + 1; }

inline void solve() {
  ll x;
  cin >> x;

  ll ans = 0;
  while(f(ans) <= x) {
    ans++;
  }

  cout << ans - 1 << '\n';
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