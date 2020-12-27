#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
  cin >> n;
  ll ans = 3 * n * n + 3 * n + 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int a = (n + 1 - i) * (n + 1 - j);
      int b = i * j;
      int gcd = __gcd(a, b);
      a /= gcd;
      b /= gcd;
      if((n + 1) % (a + b) == 0) ans--;
    }
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