#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll a, b, v, w, t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  bool ok;
  cin >> a >> v >> b >> w >> t;
  if(a < b) {
    ll x = a + t * v;
    ll y = b + t * w;
    ok = (x >= y);
  } else if(a > b) {
    ll x = a - t * v;
    ll y = b - t * w;
    ok = (x <= y);
  }
  cout << (ok ? "YES" : "NO");
  cout << '\n';

  return 0;
}
