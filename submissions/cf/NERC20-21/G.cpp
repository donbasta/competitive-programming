#include <bits/stdc++.h>
using namespace std;
/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using LD = long double;

const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};

inline int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
inline LD dist(point a, point b) { return (b-a).norm(); }
inline LD dist2(point a, point b) { return (b-a).norm_sq(); }
inline LD angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}
inline point bisector(point a, point b) { return a * b.norm() + b * a.norm(); }

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta, point tb) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); } // minor
  operator bool() { return !(ab == point()); } // minor
  // Line
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return eq(ab % (p-a), 0);
  }
  LD distLine(point p) {
    if (ab == point()) return dist(a, p);
    return fabs((p-a) % ab)/ab.norm();
  }
  point projection(point p) {
    if (ab == point()) return a;
    return a + ab * ((p-a) * ab / ab.norm_sq());
  }
  point reflection(point p) {
    return projection(p) * 2.0 - p;
  }
  // Segment
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  LD distSegment(point p) {
    if (le((p-a) * ab, 0)) return dist(a, p);
    if (le(0, (p-b()) * ab)) return dist(b(), p);
    return distLine(p);
  }
  point closestSegment(point p) {
    if (le((p-a) * ab, 0)) return a;
    if (le(0, (p-b()) * ab)) return b();
    return projection(p);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};

bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

const int N = 2e5;
point p[N + 10];
int n, H;

void print(point P) {
  cerr << "(" << P.x << "," << P.y << ")" << '\n';
}

void solve() {
  cin >> n >> H;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = point(x, y);
    // cin >> p[i].x >> p[i].y;
  }
  LD ans = 0;
  point eye = p[n - 1] + point(0, H);
  vector<point> st = {eye, p[n - 1]};
  for (int i = n - 2; i >= 0; i--) {
    // print(eye); print(st[1]); print(p[i]);
    if (ccw(eye, st[1], p[i]) <= 0) {
      line l1 = line(eye, st[1]);
      line l2 = line(p[i], p[i + 1]);
      point cut;
      if (areIntersect(l1, l2, cut)) {
        if (l2.onSegment(cut)) {
          ans += dist(cut, p[i]);
        }
      } else if (l1.areSame(l2)) {
        ans += dist(p[i], p[i + 1]);
      }
    }
    while ((int)st.size() >= 2 && ccw(st[st.size() - 2], st.back(), p[i]) <= 0) {
      st.pop_back();
    }
    st.push_back(p[i]);
    // cerr << ans << '\n';
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cout << fixed << setprecision(12);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}