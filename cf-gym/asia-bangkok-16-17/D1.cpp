#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MAX = 1e14;

ll ax, ay, bx, by, k, da;

ll gcd(ll a, ll b, ll& x, ll& y) {
  if(b == 0) {x = 1, y = 0; return a;}
  ll x1, y1;
  ll d = gcd(b, a % b, x1, y1);
  x = y1, y = x1 - y1 * (a / b);
  return d;
}

ll getX(ll y, ll sgn) {
  return (sgn * da + by * ax - ay * bx - y * (ax - bx)) / (by - ay);
}

ll getY(ll x) {
  return (sgn * da + by * ax - ay * bx - x * (by - ay)) / (ax - bx);
}

void solve() {
  cin >> ax >> ay >> bx >> by >> k;
  da = __gcd(abs(ax - bx), abs(ay - by));
  vector<pair<ll, ll>> ve;

  if(ax == bx) {
    ll xi, yi;
    ll c = da + by * ax - ay * bx;
    ll d = -da + by * ax - ay * bx;
    ll t = gcd(by - ay, ax - bx, xi, yi);
    xi *= (d / t);
    yi *= (d / t);
    while(cnt < k) {
      ve.push_back(cur);
      cnt++, cur++;
    }
    for(auto y : ve) {
      ll x = getX(y);
      cout << x << ' ' << y << '\n';
    }
  } else {
    int cur = 1, cnt = 0;
    while(cnt < k) {
      ve.push_back(cur);
      cnt++, cur++;
    }
    for(auto x : ve) {
      ll y = getY(x);
      cout << x << ' ' << y << '\n';
    }
  }
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