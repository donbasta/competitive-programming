#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ll f(int x) { return 1LL * x * (x + 1) / 2; }
inline int sgn(ll n) { return (n > 0 ? 1 : (n < 0 ? -1 : 0)); }

struct Point {
  ll x, y;
  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  ll operator%(const Point& p) const { return x * p.y - y * p.x; }
  bool operator<(const Point& p) const { return (y == p.y) ? x < p.x : y < p.y; }
};

inline int ccw(const Point& a, const Point& b, const Point& c) { return sgn((b - a) % (c - b)); }

int n;
vector<Point> pts;
ll luas;

inline ll calc(int start, int pos) {
  int left = pos - 2 - start;
  if(left < 0) left += n;
  int right = start - pos - 1;
  if(right < 0) right += n;
  return f(left) + f(right);
}

inline bool diluar(const Point& p) {
  ll temp = 0;
  for(int i = 0; i < n; i++) {
    int ni = (i + 1) % n;
    temp += abs((pts[i] - p) % (pts[ni] - p));
  }
  return temp != luas;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    pts.emplace_back(x, y);
  }

  for(int i = 0; i < n; i++) {
    int ni = (i + 1) % n;
    luas += pts[i] % pts[ni];
  }
  luas = abs(luas);

  int q;
  cin >> q;
  while(q--) {
    ll qx, qy;
    cin >> qx >> qy;
    Point que = Point(qx, qy);
    if(diluar(que)) {
      cout << 0 << '\n';
      continue;
    }
    int pi = 0, pj = 1;
    ll no = 0;
    while(pi < n) {
      if(ccw(pts[pi], pts[pj], que) == -1) {
        pj = (pj + 1) % n;
      } else {
        no += calc(pi, pj);
        pi++;
      }
    }
    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
    no /= 2;
    ans -= no;
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