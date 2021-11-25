#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using LD = long double;

inline int sign(LD x) { return (x == 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
    LD x, y;
    point(LD x = 0, LD y = 0) : x(x), y(y) {}
    point operator+(const point& p) const { return point(x+p.x, y+p.y); }
    point operator-(const point& p) const { return point(x-p.x, y-p.y); }
    point operator*(LD s) { return point(x*s, y*s); }
    LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
    LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
    bool operator==(const point& p) const { return (x == p.x) && (y == p.y); }
    bool operator<(const point& p) const { return (y == p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

double dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
point pivot;
bool angle_cmp(point a, point b) {
    if(ccw(pivot, a, b) == 0)
        return dist2(a, pivot) < dist2(b, pivot);
    return ccw(pivot, a, b) > 0;
}
void convexHull(vector<point>& P) {
    int i, j, n = (int) P.size();
    if (n < 3) {
        return;
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
    S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2;
    while(i < n) {
        j = (int) S.size() - 1;
        if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
        else S.pop_back();
    }
    P = S;
}

int pointVsPolygon(point p, const vector<point>& vp) {
    int wn = 0, n = (int)vp.size() - 1;
    for(int i = 0; i < n; i++) {
        int cs = ccw(vp[i+1], vp[i], p);
        if(cs == 0 && (vp[i+1]-p) * (vp[i]-p) <= 0)
            return 0;
        if(vp[i].y <= p.y) {
            if(vp[i+1].y > p.y && cs > 0)
                wn++;
        }
        else {
            if(vp[i+1].y <= p.y && cs < 0)
                wn--;
        }
    }
    return wn == 0 ? 1 : -1;
}

void solve() {
    vector<point> pts;
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        ll x, y;
        cin >> x >> y;
        pts.emplace_back(x, y);
    }
    convexHull(pts);
    // cerr << pts.size() << '\n';
    pts.emplace_back(pts[0]);
    int S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < S; i++) {
        ll x, y;
        cin >> x >> y;
        pts2.emplace_back(x, y);
        // if (pointVsPolygon(point(x, y), pts) <= 0) {
        //     ans++;
        // }
    }
    sort(pts2.begin(), pts2.end());
    cout << ans << '\n';
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