#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll c, hr, hb, wr, wb, x1, x2, y11, y2, ans1, ans2, ans;
ll xx1, yy1, k;

ll gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x111, y111;
  ll d = gcd(b, a % b, x111, y111);
  x = y111;
  y = x111 - y111 * (a / b);
  return d;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> c >> hr >> hb >> wr >> wb;

  x1 = c / wr;
  y11 = (c - wr * x1) / wb;
  y2 = c / wb;
  x2 = (c - wb * y2) / wr;
  ans1 = hr * x1 + hb * y11;
  ans2 = hr * x2 + hb * y2;
  ans = max(ans1, ans2);
  if(c % __gcd(wr, wb) == 0) {
    ll fpb = __gcd(wr, wb);
    wr /= fpb;
    wb /= fpb;
    c /= fpb;
    // cout << wr << ' ' << wb << ' ' << c << '\n';
    ll xx, yy;
    ll fpb1 = gcd(wr, wb, xx, yy);
    assert(fpb1 == 1);
    xx *= c;
    yy *= c;
    // cout << xx << ' ' << yy << '\n';

    xx1 = xx % wb;
    if(xx1 < 0) xx1 += wb;
    k = (xx1 - xx) / wb;
    yy1 = yy - k * wr;
    if(yy1 >= 0) 
      ans = max(ans, hr * xx1 + hb * yy1);

    yy1 = yy % wr;
    if(yy1 < 0) yy1 += wr;
    k = (yy1 - yy) / wr;
    xx1 = xx - k * wb;
    if(xx1 >= 0)
      ans = max(ans, hr * xx1 + hb * yy1);
  }


  cout << ans << '\n';

  return 0;
}
