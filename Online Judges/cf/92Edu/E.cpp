#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int m, d, w;

ll calc(int x) {
  return 1LL * x * (x - 1) / 2;
}

void solve() {
  cin >> m >> d >> w;
  ll ans;
  int lul = min(m, d);
  if(d == 1) {
    ans = calc(lul);
    cout << ans << '\n';
    return;
  }
  assert(d - 1 != 0);
  w = w / __gcd(w, d - 1);
  int sisa = lul % w;
  int bagi = lul / w;
  ans = 1LL * (w - sisa) * calc(bagi) + 1LL * sisa * calc(bagi + 1);
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