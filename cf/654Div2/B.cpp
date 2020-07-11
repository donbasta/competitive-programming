#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  while(tc--) {
    ll n, r;
    ll ans = 0;
    cin >> n >> r;
    if(r < n) {
      ans = r * (r + 1) / 2;
    } else {
      ans = (n - 1) * n / 2;
      ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}
