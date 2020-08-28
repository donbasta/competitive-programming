#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld EPS = 1e-12, PI = acos(-1);
inline bool eq(ld a, ld b) { return fabs(a-b) < EPS; }
inline bool lt(ld a, ld b) { return a + EPS < b; }
inline bool le(ld a, ld b) { return a < b + EPS; }
inline int sign(ld x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }
inline ld sq(ld x) { return x * x; }

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(ld s) { return point(x*s, y*s); }
  point operator/(ld s) { return point(x/s, y/s); }
  point rot90() const { return point(-y, x); }
  ld operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  ld norm_sq() { return *this * *this; }
  ld norm() { return sqrt(*this * *this); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};

struct Circle {
  point o;
  ld r;
  Circle(point o = point(), ld r = 0.) : o(o), r(r) {}
  friend vector<point> operator& (const Circle& c1, const Circle& c2) {
    ld dis = (c1.o - c2.o).norm();
    if(lt(c1.r + c2.r, dis) || lt(dis, fabs(c1.r - c2.r))) 
      return vector<point>();
    ld dt = (sq(c1.r) - sq(c2.r)) / dis;
    ld d1 = (dis + dt) / 2;
    point dir = (c2.o - c1.o) / dis;
    point pcrs = c1.o + dir * d1;
    dt = sqrtl(max(0.0L, sq(c1.r) - sq(d1)));
    dir = dir.rot90();
    return {pcrs + dir * dt, pcrs - dir * dt};
  }
} c[5];

struct DSU {
  int pa[5], sz[5];
  void init(int n) {
    for(int i = 1; i <= n; i++) {
      pa[i] = i, sz[i] = 1;
    }
  }
  int find(int n) {
    return pa[n] == n ? pa[n] : pa[n] = find(pa[n]);
  }
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    pa[a] = b, sz[b] += sz[a];
  }
} dsu;

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> c[i].o.x >> c[i].o.y >> c[i].r;
  }
  vector<point> all;
  dsu.init(n);
  int e = 0;
  for(int i = 1; i <= n; i++) {
    vector<point> pat;
    for(int j = 1; j <= n; j++) {
      if(i == j) continue;
      vector<point> tmp = c[i] & c[j];
      if(!tmp.empty()) dsu.merge(i, j);
      for(int k = 0; k < (int)tmp.size(); k++) {
        all.push_back(tmp[k]), pat.push_back(tmp[k]);
      }
    }
    sort(pat.begin(), pat.end());
    e += unique(pat.begin(), pat.end()) - pat.begin();
  }
  sort(all.begin(), all.end());
  int v = unique(all.begin(), all.end()) - all.begin();
  int c = 0;
  for(int i = 1; i <= n; i++) {
    c += dsu.find(i) == i;
  }
  cout << e - v + c + 1 << '\n';
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