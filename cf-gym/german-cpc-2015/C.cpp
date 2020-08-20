#include<bits/stdc++.h>

#define first fi
#define second se

using namespace std;
using ll = long long;
using ld = long double;

const ld EPS = 1e-14, PI = acos(-1);
inline bool lt(ld a, ld b) { return a + EPS < b; }
inline bool le(ld a, ld b) { return a < b + EPS; }

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(ld s) { return point(x*s, y*s); }
  point operator/(ld s) { return point(x/s, y/s); }
  ld operator%(const point& p) const { return x*p.y - y*p.x; } 
};

ld signedAreaTriangle(point a, point b, point c) {
  return ((a-b) % (c-b));
}

ld polygonArea(const vector<point>& pt) {
  ld ret = 0.0;
  int sz = (int)pt.size();
  for(int i = 0; i < sz; i++) {
    int next = (i + 1) % sz;
    ret += signedAreaTriangle(pt[i], pt[next], point());
  }
  return fabs(ret);
}

vector<point> pts;
ld a, area, threshold;
int n;

ld cutSide() {
  ld dec = 0.0;
  for(int i = 0; i < n; i++) {
    int ne = (i + 1) % n;
    int pr = (i + n - 1) % n;
    point a = pts[i];
    point b = pts[ne];
    point c = pts[pr];
    dec += fabs(signedAreaTriangle(c, a, b));
  }
  return dec;
}

void solve() {
  cout << fixed << setprecision(10);
  cin >> a >> n;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    pts.emplace_back((ld)x, (ld)y);
  }
  area = polygonArea(pts);
  ld factor = ((ld)(1.0) - a);
  ld ans = cutSide() / (area * factor);
  ans = sqrtl(ans);
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