#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld EPS = 1e-9, PI = acos(-1);
inline bool eq(ld a, ld b) { return fabs(a-b) < EPS; }
inline bool lt(ld a, ld b) { return a + EPS < b; }
inline bool le(ld a, ld b) { return a < b + EPS; }
inline int sign(ld x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(ld s) { return point(x*s, y*s); }
  point operator/(ld s) { return point(x/s, y/s); }
  ld operator*(const point& p) const { return x*p.x + y*p.y; }
  ld operator%(const point& p) const { return x*p.y - y*p.x; }
  ld norm_sq() { return *this * *this; }
  ld norm() { return sqrt(*this * *this); }
  point rotate(ld cs, ld sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(ld angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ld dist(point a, point b) { return (b-a).norm(); }
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

struct line {
  point a, ab;
  line(point ta, point tb) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  ld distLine(point p) {
    if (ab == point()) return dist(a, p);
    return fabs((p-a) % ab)/ab.norm();
  }
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  ld distSegment(point p) {
    if (le((p-a) * ab, 0)) return dist(a, p);
    if (le(0, (p-b()) * ab)) return dist(b(), p);
    return distLine(p);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};


bool areIntersect(line l1, line l2, point& res) {
  if (l1.areParallel(l2)) return 0;
  ld ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

vector<point> ve;
point pos;
int n;

void solve() {
  cin >> n;
  for(int i = 0; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    if(i < n) ve.emplace_back((ld)x, (ld)y);
    else pos = point((ld)x, (ld)y);
  }
  int cnt = 0;
  line cek = line(pos, point((pos.x + 1.0), pos.y));
  ld dist = 1e18;
  vector<line> ln(n);
  for(int i = 0; i < n; i++) {
    int next = (i + 1) % n;
    ln[i] = line(ve[i], ve[next]);
  }
  for(int i = 0; i < n; i++) {
    line temp = ln[i];
    if(temp.onSegment(pos)) {
      dist = 0;
      cout << fixed << setprecision(10);
      cout << dist << '\n';
      return;
    }
    point cut = point(-1, -1);
    int dec = 0;
    if(areIntersect(temp, cek, cut)) {
      if(le(pos.x, cut.x) && temp.onSegment(cut)) cnt++;
      if(cut == ve[i]) {
        point lol = ve[(i + (n - 1)) % n];
        if(ccw(pos, cut, ve[next]) * ccw(pos, cut, lol) != 1) {
          dec++;
        }
      }
    }
    if(cut == ve[i] || temp.areSame(cek)) {

    }
    dist = min(dist, temp.distSegment(pos));
  }
  // cerr << cnt << '\n';
  if(cnt & 1) {
    cout << fixed << setprecision(10);
    cout << dist << '\n';
  } else {
    cout << -1 << '\n';
  }
  return;
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