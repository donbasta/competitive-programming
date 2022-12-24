#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using LD = long long;
inline bool eq(LD a, LD b) { return a == b; }
inline bool lt(LD a, LD b) { return a < b; }
inline bool le(LD a, LD b) { return a <= b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
    LD x, y;
    point(LD tx = 0, LD ty = 0) : x(tx), y(ty) {}
    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
    point operator*(LD s) { return point(x * s, y * s); }
    point operator/(LD s) { return point(x / s, y / s); }
    LD operator*(const point& p) const { return x * p.x + y * p.y; }  // dot
    LD operator%(const point& p) const { return x * p.y - y * p.x; }  // cross
    LD norm_sq() { return *this * *this; }
    bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
ostream& operator<<(ostream& os, point p) {
    return os << "(" << p.x << ", " << p.y << ")";
}
// -1 : clockwise, 0 = collinear, 1 : counter-clockwise
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }

LD d_area(point a, point b, point c) {
    return abs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

ld dis(point a, point b) {
    return sqrtl((a - b).norm_sq());
}

ld perimeter(point a, point b, point c) {
    return dis(a, b) + dis(b, c) + dis(c, a);
}

LD inside(point a, point b, point c, point d) {
    int p = (ccw(d, a, b));
    int q = (ccw(d, b, c));
    int r = (ccw(d, c, a));
    if ((p == q) && (q == r)) {
        return true;
    }
    return false;
}

void sortCircular(vector<pair<point, int>>& events) {
    vector<pair<point, int>> upper, lower;
    for (pair<point, int>& e : events) {
        if (point() < e.first)
            upper.push_back(e);
        else
            lower.push_back(e);
    }
    auto cmp = [](pair<point, int> lef, pair<point, int> rig) {
        int dir = sign(lef.first % rig.first);
        if (dir == 0)
            return lef.first.norm_sq() < rig.first.norm_sq();
        return dir > 0;
    };
    sort(upper.begin(), upper.end(), cmp);
    sort(lower.begin(), lower.end(), cmp);
    for (int i = 0; i < (int)upper.size(); ++i)
        events[i] = upper[i];
    for (int i = 0; i < (int)lower.size(); ++i)
        events[i + upper.size()] = lower[i];
}

pair<LD, LD> reduce(point p) {
    LD X = p.x;
    LD Y = p.y;
    LD fpb = __gcd(X, Y);
    fpb = abs(fpb);
    return make_pair(X / fpb, Y / fpb);
}

int n;

void solve() {
    cin >> n;
    vector<point> pt(n);
    for (int i = 0; i < n; i++) {
        cin >> pt[i].x >> pt[i].y;
    }
    point pp;
    cin >> pp.x >> pp.y;
    if (n < 3) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    ld ans = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (d_area(pt[i], pt[j], pt[k]) == 0LL) {
                    continue;
                }
                if (inside(pt[i], pt[j], pt[k], pp)) {
                    ans = min(ans, perimeter(pt[i], pt[j], pt[k]));
                }
            }
        }
    }
    vector<pair<point, int>> ve;
    map<pair<int, int>, point> mp;
    for (int i = 0; i < n; i++) {
        pt[i] = pt[i] - pp;
        ve.emplace_back(pt[i], i);
    }
    sortCircular(ve);
    mp[reduce(ve[0].first)] = ve[0].first;
    for (int i = 1; i < n; i++) {
        if (reduce(ve[i].first) != reduce(ve[i - 1].first)) {
            mp[reduce(ve[i].first)] = ve[i].first;
        }
    }
    vector<pair<int, int>> cont;
    for (auto j : mp) {
        cont.emplace_back(j.first);
    }
    int sz = (int)cont.size();
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if ((cont[i].first + cont[j].first == 0) && (cont[i].second + cont[j].second == 0)) continue;
            point c = mp[cont[i]];
            point d = mp[cont[j]];
            pair<int, int> pa = make_pair(-cont[i].first, -cont[i].second);
            pair<int, int> pb = make_pair(-cont[j].first, -cont[j].second);
            if ((mp.find(pa) != mp.end()) && (mp.find(pb) != mp.end())) {
                ans = min(ans, perimeter(mp[pa], c, mp[pb]) + perimeter(mp[pa], c, d) - dis(mp[pa], c) * 2);
            }
        }
    }

    if (ans >= 1e18) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cout << fixed << setprecision(9) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}