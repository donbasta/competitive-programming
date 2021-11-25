#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll ceil(ll a, ll b) {
  return (a + b - 1) / b;
}

void solve() {
  ll w,h,a,b,m,c;
  cin >> w >> h >> a >> b >> m >> c;

  ll need = ceil(ceil(w,a) * ceil(h,b), 10) * m;
  ll cost = 0;
  if (w % a != 0 && h % b != 0) {
    cost = (w + h) * c;
  } else if (w % a != 0) {
    cost = h * c;
  } else if (h % b != 0) {
    cost = w * c;
  }
  // cerr << need << ' ' << cost << '\n';
  need += cost;
  cout << need << '\n';
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