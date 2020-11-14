#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll f(ll x) {
  return x * (x+1) / 2;
}

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    ans += f(b) - f(a-1);
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