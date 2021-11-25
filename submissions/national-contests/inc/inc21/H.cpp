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

void convexHullCheck(vector<pair<point, int>>& P) {
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
  vector<pair<point, int>> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    if(j < 1 || ccw(S[j-1].first, S[j].first, P[i].first) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
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

int pointVsPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size();
  for(int i = 0; i < n; i++) {
    int cs = ccw(vp[(i+1)%n], vp[i], p);
    if(cs == 0 && (vp[(i+1)%n]-p) * (vp[i]-p) <= 0)
      return 0; // between(vp[i], p, vp[i+1])
    if(vp[i].y <= p.y) {
      if(vp[(i+1)%n].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[(i+1)%n].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn == 0 ? 1 : -1;
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
    vector<pair<point, int>> cp = pts;
    vector<pair<point, int>> cp2 = pts;
    convexHull(cp);
    convexHullCheck(cp2);
    int SZ = cp.size();
    if (cp2.size() == 2) { //segaris semua
        for (int i = 0; i < n; i++) {
            cout << n - 1 << '\n';
        }
        return;
    }
    // cerr << "convexHull:\n";
    // cerr << "size: " << cp.size() << '\n';
    // for (auto e : cp) {
    //     cerr << "(" << e.first.x << "," << e.first.y << ") " << e.second << '\n';
    // }

    point center;
    LD sumX = 0, sumY = 0;
    for (auto e : cp) {
        sumX += e.first.x, sumY += e.first.y;
    }
    center.x = sumX / SZ;
    center.y = sumY / SZ;

    vector<pair<LD, int>> radianAngle;
    bool adaOrigin = false;
    for (int i = 0; i < n; i++) {
        point trans = pts[i].first - center;
        if (trans == point()) {
            adaOrigin = true;
            continue;
        }
        LD angle;
        if (trans.x == 0 && trans.y > 0) {
            angle = PI / 2;
        } else if (trans.x == 0 && trans.y < 0) {
            angle = PI * 3 / 2;
        } else {
            angle = atan(trans.y / trans.x);
            if (trans.x < 0) angle += PI;
            else if (trans.y < 0) {
                angle += PI * 2;
            }
        }
        radianAngle.emplace_back(angle, i);
    }
    sort(radianAngle.begin(), radianAngle.end());
    int RD = radianAngle.size();
    // cerr << "RD: " << RD << '\n';
    vector<int> start(n);
    for (int i = 0; i < RD; i++) {
        start[radianAngle[i].second] = i;
    }

    vector<int> ans(n);
    for (int i = 0; i < SZ; i++) {
        // cerr << "lol " << i << '\n';
        point t1 = cp[i].first;
        point t2 = cp[(i + 1) % SZ].first;
        point t3 = cp[(i + 2) % SZ].first;
        int hilang = cp[(i + 1) % SZ].second;
        vector<point> triangle = vector<point>{t1, t2, t3};
        vector<pair<point, int>> tmp;

        int lulz = (start[cp[i].second] + RD - 1) % RD;
        while (ccw(center, pts[radianAngle[lulz].second].first, t1) == 0) {
            tmp.emplace_back(pts[radianAngle[lulz].second].first, -1);
            lulz = (lulz + RD - 1) % RD;
        }
        for (int j = start[cp[i].second]; j != start[cp[(i + 2) % SZ].second]; j = (j + 1) % RD) {
            if (j == start[cp[(i + 1) % SZ].second]) {
                continue;
            }
            if (pointVsPolygon(pts[radianAngle[j].second].first, triangle) != 1) {
                tmp.emplace_back(pts[radianAngle[j].second].first, -1);
            }
        }
        if (adaOrigin) {
            // cerr << "ilang\n";
            // cerr << pointVsPolygon(center, triangle) << '\n';
            // cerr << center.x << ' ' << center.y << '\n';
            // for (auto e : triangle) {
            //     cerr << e.x << ' ' << e.y << '\n'; 
            // }
            if (pointVsPolygon(center, triangle) != 1) {
                // cerr << "wahaha " << hilang << '\n';
                tmp.emplace_back(center, -1);
            }
        }
        lulz = (start[cp[(i + 2) % SZ].second] + 1) % RD;
        while (ccw(center, pts[radianAngle[lulz].second].first, t3) == 0) {
            tmp.emplace_back(pts[radianAngle[lulz].second].first, -1);
            lulz = (lulz + RD - 1) % RD;
        }
        tmp.emplace_back(t3, -1);
        // cerr << hilang << ' ' << tmp.size() << '\n';
        // for (auto e : tmp) {
        //     cerr << "(" << e.first.x << "," << e.first.y << ") " << e.second << '\n';
        // }
        convexHull(tmp);
        // cerr << tmp.size() << '\n';
        int rem = 2;
        for (auto e : tmp) {
            if (e.first == t1 || e.first == t3) continue;
            if (ccw(e.first, t1, t3) == 0) {
                rem++;
            }
        }
        ans[hilang] = SZ - 1 + tmp.size() - rem;
    }


    vector<bool> inBoundary(n);
    for (auto e : cp) {
        inBoundary[e.second] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!inBoundary[i]) {
            cout << cp.size() << '\n';
        } else {
            cout << ans[i] << '\n';
        }
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