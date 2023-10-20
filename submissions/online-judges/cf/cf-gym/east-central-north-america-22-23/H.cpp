#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using LD = long double;

const LD EPS = 1e-6, PI = acos(-1), XXX = 1e8;
inline bool eq(LD a, LD b) { return fabs(a - b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
    LD x, y;
    point(LD x = 0, LD y = 0) : x(x), y(y) {}
    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
    point operator*(LD s) { return point(x * s, y * s); }
    point operator/(LD s) { return point(x / s, y / s); }
    LD operator*(const point& p) const { return x * p.x + y * p.y; }  // dot
    LD operator%(const point& p) const { return x * p.y - y * p.x; }  // cross
    LD norm_sq() { return *this * *this; }
    LD norm() { return sqrt(*this * *this); }
    point rotate(LD cs, LD sn) { return point(x * cs - y * sn, x * sn + y * cs); }
    point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
    bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b - a).norm(); }
LD dist2(point a, point b) { return (b - a).norm_sq(); }
LD angle(point a, point o, point b) {
    point oa = a - o, ob = b - o;
    return acos(oa * ob / (oa.norm() * ob.norm()));
}
point bisector(point a, point b) { return a * b.norm() + b * a.norm(); }

struct line {
    point a, ab;  // p(t) = a + ab * t
    line(point ta, point tb) {
        if (tb < ta) swap(ta, tb);
        a = ta;
        ab = tb - ta;
    }
    point b() { return a + ab; }
    bool isLine() { return !(ab == point()); }    // minor
    operator bool() { return !(ab == point()); }  // minor
    // Line
    bool onLine(point p) {
        if (ab == point()) return a == p;
        return eq(ab % (p - a), 0);
    }
    LD distLine(point p) {
        if (ab == point()) return dist(a, p);
        return fabs((p - a) % ab) / ab.norm();
    }
    point projection(point p) {
        if (ab == point()) return a;
        return a + ab * ((p - a) * ab / ab.norm_sq());
    }
    point reflection(point p) {
        return projection(p) * 2.0 - p;
    }
    // Segment
    bool onSegment(point p) {
        if (ab == point()) return a == p;
        point pa = a - p, pb = b() - p;
        return eq(pa % pb, 0) && le(pa * pb, 0);
    }
    LD distSegment(point p) {
        if (le((p - a) * ab, 0)) return dist(a, p);
        if (le(0, (p - b()) * ab)) return dist(b(), p);
        return distLine(p);
    }
    point closestSegment(point p) {
        if (le((p - a) * ab, 0)) return a;
        if (le(0, (p - b()) * ab)) return b();
        return projection(p);
    }
    bool areParallel(line l) {
        return eq(ab % l.ab, 0);
    }
    bool areSame(line l) {
        return areParallel(l) && onLine(l.a) && l.onLine(a);
    }
};

point lineIntersectSeg(point p, point q, point A, point B) {
    LD a = B.y - A.y;
    LD b = A.x - B.x;
    LD c = B.x * A.y - A.x * B.y;
    LD u = fabs(a * p.x + b * p.y + c);
    LD v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

void solve() {
    int n;
    cin >> n;
    vector<point> PTS;
    for (int i = 0; i < n + 1; i++) {
        LD x, y;
        cin >> x >> y;
        PTS.emplace_back(x, y);
    }
    LD DX, DY, sx, sy, r, c, VELO;
    cin >> c >> sx >> sy >> r >> DX >> DY >> VELO;
    point SS(sx, sy);
    point RR(sx + DX, sy + DY);

    point CAM;
    bool found = false;
    for (int i = 0; i < n + 1; i++) {
        if (PTS[i].x == c) {
            found = true;
            CAM = PTS[i];
            break;
        } else if (PTS[i].x > c) {
            found = true;
            CAM = point(c, PTS[i - 1].y + (c - PTS[i - 1].x) / (PTS[i].x - PTS[i - 1].x) * (PTS[i].y - PTS[i - 1].y));
            break;
        }
    }
    assert(found);

    // find right viewpoint space
    vector<point> L, R;
    for (int i = 0; i < n + 1; i++) {
        if (PTS[i].x < c)
            continue;
        else if (PTS[i].x == c) {
            R.push_back(PTS[i]);
        } else {
            if (R.size() == 0) {
                R.push_back(CAM);
                R.push_back(PTS[i]);
            } else if (R.size() == 1) {
                R.push_back(PTS[i]);
            } else {
                if (ccw(R[0], R.back(), PTS[i]) <= 0) {
                    continue;
                } else {
                    point Z = lineIntersectSeg(PTS[i - 1], PTS[i], R[0], R.back());
                    if (R.back() == PTS[i - 1]) {
                        R.push_back(PTS[i]);
                    } else {
                        R.push_back(Z);
                        R.push_back(PTS[i]);
                    }
                }
            }
        }
    }
    // R.push_back(point(R.back().x + XXX, R.back().y));
    if (R.size() >= 2) {
        LD dx = R.back().x - R[0].x;
        LD dy = R.back().y - R[0].y;
        R.push_back(point(R[0].x + dx * XXX, R[0].y + dy * XXX));
    } else {
        R.push_back(point(R[0].x + XXX, R[0].y));
    }

    // find left viewpoint space
    for (int i = n; i >= 0; i--) {
        if (PTS[i].x > c) {
            continue;
        } else if (PTS[i].x == c) {
            L.push_back(PTS[i]);
        } else {
            if (L.size() == 0) {
                L.push_back(CAM);
                L.push_back(PTS[i]);
            } else if (L.size() == 1) {
                L.push_back(PTS[i]);
            } else {
                if (ccw(L[0], L.back(), PTS[i]) >= 0) {
                    continue;
                } else {
                    point Z = lineIntersectSeg(PTS[i], PTS[i + 1], L[0], L.back());
                    if (L.back() == PTS[i + 1]) {
                        L.push_back(PTS[i]);
                    } else {
                        L.push_back(Z);
                        L.push_back(PTS[i]);
                    }
                }
            }
        }
    }
    // L.push_back(point(L.back().x - XXX, L.back().y));
    if (L.size() >= 2) {
        LD dx = L.back().x - L[0].x;
        LD dy = L.back().y - L[0].y;
        L.push_back(point(L[0].x + dx * XXX, L[0].y + dy * XXX));
    } else {
        L.push_back(point(L[0].x - XXX, L[0].y));
    }

    cerr << "====\n";
    for (auto P : R) {
        cerr << P.x << ' ' << P.y << '\n';
    }
    cerr << "====\n";
    for (auto P : L) {
        cerr << P.x << ' ' << P.y << '\n';
    }
    cerr << "====\n";

    vector<point> CUTS;
    for (int i = 0; i < (int)R.size() - 1; i++) {
        if (line(SS, RR).areParallel(line(R[i], R[i + 1]))) continue;
        LD left1 = (RR - SS) % (R[i] - RR);
        LD left2 = (RR - SS) % (R[i + 1] - RR);
        // cerr << i << ' ' << left1 << ' ' << left2 << '\n';
        if (left1 < EPS && left1 > -EPS) CUTS.push_back(R[i]);
        if (left1 * left2 < -EPS) {
            point LMAO = lineIntersectSeg(R[i], R[i + 1], RR, SS);
            // cerr << "HAHA " << LMAO.x << ' ' << LMAO.y << '\n';
            if (line(SS, LMAO).onSegment(RR)) {
                CUTS.push_back(LMAO);
            }
        }
    }

    point AA = RR - SS;
    point BB = R[2] - RR;
    // cerr << "AA " << AA.x << ' ' << AA.y << '\n';
    // cerr << "BB " << BB.x << ' ' << BB.y << '\n';

    // cerr << "CUTS " << CUTS.size() << '\n';
    // for (auto P : CUTS) {
    //     cerr << P.x << ' ' << P.y << '\n';
    // }
    for (int i = 0; i < (int)L.size() - 1; i++) {
        if (line(SS, RR).areParallel(line(L[i], L[i + 1]))) continue;
        LD left1 = (RR - SS) % (L[i] - RR);
        LD left2 = (RR - SS) % (L[i + 1] - RR);
        if (left1 < EPS && left1 > -EPS) CUTS.push_back(L[i]);
        if (left1 * left2 < -EPS) {
            point LMAO = lineIntersectSeg(L[i], L[i + 1], RR, SS);
            if (line(SS, LMAO).onSegment(RR)) {
                CUTS.push_back(LMAO);
            }
        }
    }
    // cerr << "CUTS " << CUTS.size() << '\n';
    // for (auto P : CUTS) {
    //     cerr << P.x << ' ' << P.y << '\n';
    // }
    // cerr << '\n';

    if (CUTS.empty()) {
        cout << -1 << '\n';
        return;
    }
    LD mn = 1e18;
    for (auto P : CUTS) {
        mn = min(mn, P.y - sy);
    }
    // cerr << "MN " << mn << '\n';

    LD lo = 0, hi = mn;
    while (abs(lo - hi) > EPS) {
        LD mid = (lo + hi) / 2;
        LD my = sy + mid;
        LD mx = sx + mid * (DX / DY);
        point TES(mx, my);
        bool ok = false;
        for (int i = 0; i < (int)R.size() - 1; i++) {
            if (line(R[i], R[i + 1]).distSegment(TES) <= r) {
                ok = true;
            }
        }
        for (int i = 0; i < (int)L.size() - 1; i++) {
            if (line(L[i], L[i + 1]).distSegment(TES) <= r) {
                ok = true;
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    // the point is sy + lo, sx + lo * (dx / dy);
    point PUS = point(sx + lo * (DX / DY), sy + lo);

    cerr << "PUS " << PUS.x << ' ' << PUS.y << '\n';

    point INIT = point(sx, sy);
    LD DDD = dist(INIT, PUS);
    DDD /= VELO;
    cout << fixed << setprecision(9) << DDD << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}