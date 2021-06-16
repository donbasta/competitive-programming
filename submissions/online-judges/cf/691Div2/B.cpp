#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll f(ll x) {
  return (x + 1);
}

void solve() {
  int n;
  cin >> n;
  int a = (n / 2), b = n - (n / 2);
  ll ans = f(a) * f(b);
  if (n & 1) {
    ans = ans * 2;
  }
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