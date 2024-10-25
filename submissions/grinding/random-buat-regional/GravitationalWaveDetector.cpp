// https://codeforces.com/gym/104252/problem/G

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x−axis in interval [−pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }  // makes d i s t ()=1
    P perp() const { return P(-y, x); }        // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
    bool left(P p, P q) { return (q - p).cross(*this - p) >= 0; }
    bool left2(P p, P q) { return (q - p).cross(*this - p) > 0; }
};

using point_type = ll;
using P = Point<point_type>;

void normalize(vector<P>& p) {
    int n = p.size();
    if (p[2].left2(p[0], p[1])) reverse(p.begin(), p.end());
    int pi = min_element(p.begin(), p.end()) - p.begin();
    vector<P> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = p[(pi + i) % n];
    }
    p.swap(s);
}

vector<P> hull(vector<P> p) {
    if (p.size() < 3) return p;
    vector<P> r;
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i++) {
        while (r.size() >= 2 && r.back().left(r[r.size() - 2], p[i])) r.pop_back();
        r.push_back(p[i]);
    }
    r.pop_back();
    int k = r.size();
    for (int i = p.size() - 1; i >= 0; i--) {
        while (r.size() >= k + 2 && r.back().left(r[r.size() - 2], p[i])) r.pop_back();
        r.push_back(p[i]);
    }
    r.pop_back();
    normalize(r);
    return r;
}

vector<P> minkowski(vector<P> p1, vector<P> p2) {
    int i1 = 0, i2 = 0;
    int s1 = p1.size(), s2 = p2.size();
    for (int i = 0; i < s1; i++) {
        if (p1[i] < p1[i1]) i1 = i;
    }
    for (int i = 0; i < s2; i++) {
        if (p2[i] < p2[i2]) i2 = i;
    }
    vector<P> ret = {p1[i1] + p2[i2]};
    for (int i = 1; i < s1 + s2; i++) {
        P a = p1[(i1 + 1) % s1] + p2[i2], b = p1[i1] + p2[(i2 + 1) % s2];
        if (b.left(ret.back(), a)) {
            ret.push_back(b);
            i2 = (i2 + 1) % s2;
        } else {
            ret.push_back(a);
            i1 = (i1 + 1) % s1;
        }
    }
    return ret;
}

vector<P> mul(vector<P> poly, point_type coef) {
    for (auto& e : poly) {
        e = e * coef;
    }
    return poly;
}

bool inside_polygon(P p, const vector<P>& poly) {
    if (p.left2(poly[0], poly[1]) || p.left2(poly.back(), poly[0])) {
        return 0;
    }
    int a = 1, b = poly.size() - 1;
    while (b - a > 1) {
        int c = (b + a) >> 1;
        if (!p.left2(poly[0], poly[c]))
            a = c;
        else
            b = c;
    }
    return !p.left2(poly[a], poly[a + 1]);
}

void el_psy_congroo() {
    int m1, m2, n;

    cin >> m1;
    vector<P> p1(m1);
    for (int i = 0; i < m1; i++) {
        int x, y;
        cin >> x >> y;
        p1[i] = P(x, y);
    }

    cin >> m2;
    vector<P> p2(m2);
    for (int i = 0; i < m2; i++) {
        int x, y;
        cin >> x >> y;
        p2[i] = P(x, y);
    }

    // reverse to make it clockwise
    reverse(p1.begin(), p1.end());
    reverse(p2.begin(), p2.end());

    vector<P> c1 = minkowski(mul(p1, 2), mul(p2, -1));
    vector<P> c2 = minkowski(mul(p1, -1), mul(p2, 2));
    vector<P> c3 = minkowski(p1, p2);
    c1 = hull(c1), c2 = hull(c2), c3 = hull(c3);

    cin >> n;
    string ret(n, 'N');
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        P qq = P(x, y);
        bool ok1 = inside_polygon(qq, c1);
        bool ok2 = inside_polygon(qq, c2);
        bool ok3 = inside_polygon(qq * 2, c3);
        if (ok1 || ok2 || ok3) {
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
        el_psy_congroo();
    }

    return 0;
}