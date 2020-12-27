#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  ll operator%(const point& p) const { return x*p.y - y*p.x; }
  bool operator==(const point& p) const { return (x == p.x) && (y == p.y); }
  bool operator<(const point& p) const { return (y == p.y) ? (x < p.x) : (y < p.y); }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

ll doubleSignedAreaTriangle(point a, point b, point c) {
  return (a-b) % (c-b);
}

point pivot;
bool angle_cmp(point a, point b) {
  if(ccw(pivot, a, b) == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b) > 0;
}

vector<point> convexHull(const vector<point>& P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return P;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  vector<point> S;
  S.push_back(P[0]), S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  return S;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }
  ch = convexHull(points);

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