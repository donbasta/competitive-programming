#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll h, w;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> h >> w;
  if(h % 3 == 0 || w % 3 == 0) {
    cout << 0 << '\n';
    return 0;
  }
  ll ans = min(h, w);
  for(int lol = 0; lol < 2; lol++) {
    for(int i = 1; i < h; i++) {
      ll l1 = 1LL * i * w;
      ll l2 = 1LL * (h - i) * (w / 2);
      ll l3 = 1LL * (h - i) * w - l2;
      ll mn = min(l1, min(l2, l3));
      ll mx = max(l1, max(l2, l3));
      ans = min(ans, mx - mn);
    }
    swap(h, w);
  }
  cout << ans << '\n';
  return 0;
}