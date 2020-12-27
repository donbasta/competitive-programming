#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const ld MAX = 1e18;
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
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
 
struct line {
  point a, ab;
  line(point ta, point tb) {
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); }
  operator bool() { return !(ab == point()); }
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return eq(ab % (p-a), 0);
  }
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
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
  ld ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}
 
int n;
int x1, x2, y1, y2;
point A[4];
 
ld getTime(line l, point p) {
  assert(l.onLine(p));
  if(l.ab.x != 0) return (p - l.a).x / l.ab.x;
  return (p - l.a).y / l.ab.y;
}
 
void solve() {
  cerr << fixed << setprecision(20);
  cout << fixed << setprecision(15);
  cin >> n;
  cin >> x1 >> y1 >> x2 >> y2;
  A[0] = point((ld)x1, (ld)y1);
  A[1] = point((ld)x1, (ld)y2);
  A[2] = point((ld)x2, (ld)y2);
  A[3] = point((ld)x2, (ld)y1);
  vector<line> trajectories;
  for(int i = 0; i < n; i++) {
    int rx, ry, vx, vy;
    cin >> rx >> ry >> vx >> vy;
    point init = point((ld)rx, (ld)ry);
    point dir = point((ld)(rx + vx), (ld)(ry + vy));
    trajectories.emplace_back(init, dir);
  }
  ld mn = 0., mx = MAX;
  for(int i = 0; i < n; i++) {
    vector<ld> time;
    if(!trajectories[i].isLine()) {
      bool ok = true;
      point pos = trajectories[i].a;
      ok &= (pos.x > x1 && pos.x < x2 && pos.y > y1 && pos.y < y2);
      if(!ok) {cout << -1 << '\n'; return;}
      continue;
    }
    for(int j = 0; j < 4; j++) {
      int nj = (j + 1) % 4;
      line sisi = line(A[j], A[nj]);
      if(!sisi.isLine()) {cout << -1 << '\n'; return;}
      if(sisi.areSame(trajectories[i])) {cout << -1 << '\n'; return;}
      point temp;
      ld t = 2. * MAX;
      if(areIntersect(sisi, trajectories[i], temp)) {
        if(sisi.onSegment(temp)){
          t = getTime(trajectories[i], temp);
        }
      }
      time.emplace_back(max(t, (ld)0.0));
    }
    sort(time.begin(), time.end());
    ld te[2];
    te[0] = time[0];
    int cnt = 1;
    for(int j = 1; j < 4; j++) {
      if(time[j] == (ld)2. * MAX) continue;
      if(time[j] == time[j - 1]) continue;
      te[cnt++] = time[j];
      if(cnt >= 2) break;
    }
    if(cnt == 1) {cout << -1 << '\n'; return;}
    if(te[0] >= mx) {cout << -1 << '\n'; return;}
    if(te[1] <= mn) {cout << -1 << '\n'; return;}
    mx = min(mx, te[1]);
    mn = max(mn, te[0]);
  }
  cout << mn << '\n';
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