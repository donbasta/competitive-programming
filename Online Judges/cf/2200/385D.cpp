#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 20;

const ld EPS = 1e-10, PI = acos(-1), INF = 1e18;
inline bool eq(ld a, ld b) { return fabs(a-b) < EPS; }
inline bool lt(ld a, ld b) { return a + EPS < b; }
inline bool le(ld a, ld b) { return a < b + EPS; }

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }
  point operator*(ld s) { return point(x * s, y * s); }
  point operator/(ld s) { return point(x / s, y / s); }
  ld operator*(const point& p) const { return x * p.x + y * p.y; }
  ld operator%(const point& p) const { return x * p.y - y * p.x; }
  point rotate(ld cs, ld sn) { return point(x * cs - y * sn, x * sn + y * cs); }
  point rotate(ld angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
};

struct line {
  point a, ab;
  line(point ta, point tb) {
    a = ta; ab = tb - ta;
  }
  bool areParallel(line l) { return eq(ab % l.ab, 0); }
};

bool areIntersect(line l1, line l2, point& res) {
  if (l1.areParallel(l2)) return 0;
  ld ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls / rs;
  return 1;
}

ld dp[(1 << N) + 10];
int n, l, r;

struct Lamp {
  point p;
  int a;
  Lamp(ld x = 0, ld y = 0, int a = 0) : a(a) {
    p = point(x, y);
  }
};

ld flood(ld cur, const Lamp& lamp) {
  point axis = lamp.p;
  point now = point(cur, 0);
  ld angle = ((ld)(lamp.a)) * PI / ((ld)(180));
  point curRotated = (now - axis).rotate(angle) + axis;
  point next;
  line res = line(axis, curRotated);
  line seg = line(point((ld)l, (ld)0), point((ld)r, (ld)0));
  if(areIntersect(res, seg, next)) {
    if(le(r, next.x) || le(next.x, cur)) return -INF;
    else return next.x;
  }
  return -INF;
}

void solve() {
  cout << fixed << setprecision(10);
  cin >> n >> l >> r;
  vector<Lamp> la;
  for(int i = 0; i < n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    la.emplace_back((ld)x, (ld)y, a);
  }
  for(int i = 1; i < (1 << n); i++) {
    for(int k = 0; k < n; k++) {
      if(!(i & (1 << k))) continue;
      ld curRight = dp[i ^ (1 << k)];
      ld nextRight = flood(curRight + (ld)l, la[k]);
      if(nextRight == -INF) {cout << (ld)(r - l) << '\n'; return;}
      dp[i] = max(dp[i], nextRight - (ld)l);
    }
  }
  cout << min((ld)(r - l), dp[(1 << n) - 1]) << '\n';
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