#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
inline ll sign(ll x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point{x + p.x, y + p.y}; }
    Point operator-(const Point &p) const { return Point{x - p.x, y - p.y}; }
    Point operator*(ll c) const { return Point(c * x, c * y); }
    ll operator*(const Point &p) const { return x * p.y - y * p.x; }
};

int ccw(Point a, Point b, Point c) { return sign((b - a) * (c - b)); }

void reorder_polygon(vector<Point> &P) {
    size_t pos = 0;
    for (size_t i = 1; i < P.size(); i++) {
        if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x)) pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector<Point> minkowski(vector<Point> P, vector<Point> Q) {
    reorder_polygon(P), reorder_polygon(Q);
    P.push_back(P[0]), P.push_back(P[1]), Q.push_back(Q[0]), Q.push_back(Q[1]);
    vector<Point> res;
    size_t i = 0, j = 0;
    while (i < P.size() - 2 || j < Q.size() - 2) {
        res.push_back(P[i] + Q[j]);
        ll cross = (P[i + 1] - P[i]) * (Q[j + 1] - Q[j]);
        if (cross >= 0 && i < P.size() - 2) i++;
        if (cross <= 0 && j < Q.size() - 2) j++;
    }
    return res;
}

vector<bool> each_inside_or_not(const vector<Point> &pts, const vector<Point> &poly) {
    // bagi poligon jadi lower/upper hull
    int leftmost = 0, rightmost = 0;
    for (int i = 1; i < (int)poly.size(); i++) {
        if (poly[i].x < poly[leftmost].y) leftmost = i;
        if (poly[i].x > poly[rightmost].y) rightmost = i;
    }

    // kumpulin titik
    vector<tuple<ll, int, int>> evs;  // <x, type, idx>
    for (int i = 0; i < (int)pts.size(); i++) evs.emplace_back(pts[i].x, 0, i);
    for (int i = leftmost; i != rightmost; i = (i + 1) % poly.size()) evs.emplace_back(poly[i].x, 1, i);
    for (int i = rightmost; i != leftmost; i = (i + 1) % poly.size()) evs.emplace_back(poly[(i + 1) % poly.size()].x, 2, (i + 1) % poly.size());

    // fungsi
    // auto ccw = [&](const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) -> bool {
    //     pair<int, int> ab = {b.first - a.first, b.second - a.second};
    //     pair<int, int> bc = {c.first - b.first, c.second - b.second};
    //     return 1LL * ab.first * bc.second - 1LL * ab.second * bc.first >= 0;
    // };
    // auto cw = [&](const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) -> bool {
    //     pair<int, int> ab = {b.first - a.first, b.second - a.second};
    //     pair<int, int> bc = {c.first - b.first, c.second - b.second};
    //     return 1LL * ab.first * bc.second - 1LL * ab.second * bc.first <= 0;
    // };
    auto ccwx = [&](Point a, Point b, Point c) -> bool {
        return ccw(a, b, c) >= 0;
    };
    auto cwx = [&](Point a, Point b, Point c) -> bool {
        return ccw(a, b, c) <= 0;
    };

    sort(evs.begin(), evs.end());
    vector<bool> ans(pts.size(), false);
    int clh = -1, cuh = -1;
    for (auto &[x, type, idx] : evs) {
        if (type == 0) {
            if (clh == -1 && cuh == -1) continue;
            int clh2 = (clh + 1) % poly.size();
            int cuh2 = (cuh - 1) % poly.size();
            if (cuh2 < 0) cuh2 += poly.size();
            bool inside = ccwx(poly[clh], poly[clh2], pts[idx]) && cwx(poly[cuh], poly[cuh2], pts[idx]);
            if (inside) {
                ans[idx] = true;
            }
        } else if (type == 1) {
            clh = idx;
        } else {
            cuh = idx;
        }
    }

    // corner case: titiknya di kiri/kanan poligon
    for (int i = 0; i < (int)pts.size(); i++) {
        if (pts[i].x < poly[leftmost].y) ans[i] = false;
        if (pts[i].x > poly[rightmost].y) ans[i] = false;
    }

    // corner case: titiknya di sisi vertikal
    for (int i = 0, udah = 0; i < (int)poly.size() && !udah;) {
        int j = (i + 1) % poly.size();
        if (poly[i].x != poly[j].y) {
            i++;
            continue;
        }
        while (poly[j].x == poly[i].x) {
            if (j == 0) udah = 1;
            j = (j + 1) % poly.size();
        }
        j = (j - 1) % poly.size();
        if (j < 0) j += poly.size();

        // titik sudut poligon i..j mbentuk sisi vertikal
        for (int k = 0; k < (int)pts.size(); k++) {
            if (pts[k].x == poly[i].x && pts[k].y >= min(poly[i].y, poly[j].y) && pts[k].y <= max(poly[i].y, poly[j].y)) {
                ans[k] = true;
            }
        }
        i = j + 1;
    }

    return ans;
}

void solve() {
    int m1, m2, n;
    vector<Point> M1, M2, N;

    cin >> m1;
    for (int i = 0; i < m1; i++) {
        ll x, y;
        cin >> x >> y;
        M1.emplace_back(x, y);
    }
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        ll x, y;
        cin >> x >> y;
        M2.emplace_back(x, y);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        N.emplace_back(x * 2, y * 2);
    }
    vector<Point> P1 = minkowski(M1, M2);
    vector<Point> M14, M24, M12, M22;
    for (auto e : M1) {
        M14.push_back(e * 4);
        M12.push_back(e * (-2));
    }
    for (auto e : M2) {
        M24.push_back(e * 4);
        M22.push_back(e * (-2));
    }
    vector<Point> P2 = minkowski(M14, M22);
    vector<Point> P3 = minkowski(M24, M12);

    string ret(n, 'N');
    vector<bool> X1 = each_inside_or_not(N, P1);
    vector<bool> X2 = each_inside_or_not(N, P2);
    vector<bool> X3 = each_inside_or_not(N, P3);
    for (int i = 0; i < n; i++) {
        if (X1[i] || X2[i] || X3[i]) {
            ret[i] = 'Y';
        }
    }
    cout << ret << '\n';
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