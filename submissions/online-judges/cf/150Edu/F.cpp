#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    Point operator+(const Point& p) const { return Point{x + p.x, y + p.y}; }
    Point operator-(const Point& p) const { return Point{x - p.x, y - p.y}; }
    ll operator^(const Point& p) const { return x * p.y - y * p.x; }
};

void reorder_polygon(vector<Point>& P) {
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
        ll cross = (P[i + 1] - P[i]) ^ (Q[j + 1] - Q[j]);
        if (cross >= 0 && i < P.size() - 2) i++;
        if (cross <= 0 && j < Q.size() - 2) j++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> T;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        T.emplace_back(a - b, c - d);
    }
    const function<vector<Point>(int, int)> merge = [&](int l, int r) -> vector<Point> {
        if (l == r) {
            return vector<Point>{Point{0, 0}, T[l]};
        }
        int mid = (l + r) >> 1;
        return minkowski(merge(l, mid), merge(mid + 1, r));
    };
    vector<Point> minkowski_sum = merge(0, n - 1);
    ld ans = 0;
    for (auto e : minkowski_sum) {
        ld ex = (ld)e.x, ey = (ld)e.y;
        ans = max(ans, ex * ex + ey * ey);
    }
    cout << fixed << setprecision(10) << ans << '\n';
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