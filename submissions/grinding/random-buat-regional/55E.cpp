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
    bool right(P p, P q) { return (q - p).cross(*this - p) <= 0; }
    bool right2(P p, P q) { return (q - p).cross(*this - p) < 0; }
};

using point_type = ll;
using P = Point<point_type>;

ll solve(P q, const vector<P>& p) {
    int n = p.size();
    ll tr = 1ll * n * (n - 1) * (n - 2) / 6;
    int ptr = 1;
    for (int i = 0; i < n; i++) {
        while (q.right(p[i], p[ptr])) ptr = (ptr + 1) % n;
        int nx = (ptr + n - 1) % n;
        if (nx < i) nx += n;
        tr -= 1ll * (nx - i) * (nx - i - 1) / 2;
    }
    return tr;
}

bool inside_polygon(P q, const vector<P>& p) {
    int n = p.size();
    if (q.left(p[0], p[1]) || q.left(p[n - 1], p[0])) return false;
    int a = 1, b = n - 2;
    while (b - a > 1) {
        int c = (b + a) >> 1;
        if (q.left(p[0], p[c])) {
            b = c;
        } else {
            a = c;
        }
    }
    return !q.left(p[a], p[a + 1]);
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<P> pt(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pt[i] = P(x, y);
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        P q = P(x, y);
        if (!inside_polygon(q, pt)) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = solve(q, pt);
        cout << ans << '\n';
    }
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