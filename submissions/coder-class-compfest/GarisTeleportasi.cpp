#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll x, y;
ll xa, ya, xb, yb;
ld koef = -1;

ld dist(ld px, ld py, ld qx, ld qy) {
  ld dx = (px - qx);
  ld dy = (py - qy);
  return hypot(dx, dy);
}

bool cek(ll a1, ll a2, ll p1, ll p2, ll q1, ll q2) {
  ll dx1 = q1 - p1, dx2 = a1 - p1;
  ll dy1 = q2 - p2, dy2 = a2 - p2;
  ll cek1 = dx1 * dx1 + dy1 * dy1;
  ll cek2 = dx1 * dx2 + dy1 * dy2;
  if(cek2 >= 0 && cek2 <= cek1) {
    koef = ((ld) (cek2)) / ((ld) (cek1));
    return true;
  }
  return false;
}

void solve() {
  cout << fixed << setprecision(12);
  cin >> x >> y;
  cin >> xa >> ya >> xb >> yb;
  if(xa == ya && xb == yb) {
    cout << dist(x, y, xa, ya) << '\n';
    return;
  }
  if(cek(x, y, xa, ya, xb, yb)) {
    cout << dist(x, y, xa + koef * (xb - xa), ya + koef * (yb - ya)) << '\n';
  } else {
    ld ans = min(dist(x, y, xa, ya), dist(x, y, xb, yb));
    cout << ans << '\n';
  }
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
