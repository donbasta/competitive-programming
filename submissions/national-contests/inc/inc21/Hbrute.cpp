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

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }
point pivot;
bool angle_cmp(pair<point, int> a, pair<point, int> b) {
    if(ccw(pivot, a.first, b.first) == 0)
        return dist2(a.first, pivot) < dist2(b.first, pivot);
    return ccw(pivot, a.first, b.first) > 0;
}

void convexHull(vector<pair<point, int>>& P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i].first < P[PO].first) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0].first;
  sort(++P.begin(), P.end(), angle_cmp);
  int k = (int)P.size()-1; while (k-1 > 0 && ccw(P[0].first, P[k-1].first, P.back().first) == 0) k--;
  reverse(P.begin() + k, P.end());
  vector<pair<point, int>> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    if(j < 1 || ccw(S[j-1].first, S[j].first, P[i].first) >= 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<point, int>> pts;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.emplace_back(point(x, y), i);
    }
    for (int i = 0; i < n; i++) {
        vector<pair<point, int>> tmp;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            tmp.emplace_back(pts[j]);
        }
        convexHull(tmp);
        cout << tmp.size() << '\n';
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