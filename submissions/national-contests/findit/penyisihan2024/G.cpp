#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define vii vector<pii>

const double epsilon = 1e-9;

template <class T>
int sgn(T x) { return (x > 0) - (x < 0); }
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
    // angle to x−axis in interva l [−pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }  // makes d is t ()=1
    P perp() const { return P(-y, x); }        // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

template <class P>
bool isSegInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
         oc = a.cross(b, c), od = a.cross(b, d);
    // Checks i f intersection is s ing le non−endpoint point .
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return true;
    return false;
}

typedef Point<double> P;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // vector<pair<P, P>> l;
    // vector<pair<P, int>> p;

    pair<P, int> p[410];
    pair<P, P> l[210];

    double sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    int ptr_p = 0, ptr_l = 0;
    p[ptr_p++] = mp(P(sx, sy), -1);
    p[ptr_p++] = mp(P(fx, fy), -1);
    // p.pb(mp(P(sx, sy), -1));
    // p.pb(mp(P(fx, fy), -1));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        l[ptr_l++] = mp(P(x1, y1), P(x2, y2));
        p[ptr_p++] = mp(P(x1, y1), i);
        p[ptr_p++] = mp(P(x2, y2), i);
        // l.pb(mp(P(x1, y1), P(x2, y2)));
        // p.pb(mp(P(x1, y1), i));
        // p.pb(mp(P(x2, y2), i));
    }

    double dist[n * 2 + 2][n * 2 + 2];
    for (int i = 0; i < n * 2 + 2; i++) {
        for (int j = 0; j < n * 2 + 2; j++) {
            dist[i][j] = 1e18;
        }
    }
    // vector<vector<double>> dist(n * 2 + 2, vector<double>(n * 2 + 2, 1e18));

    for (int i = 0; i < n * 2 + 2; i++) {
        for (int j = 0; j < n * 2 + 2; j++) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            // if (p[i].ss == p[j].ss && p[i].ss != -1) {
            //     continue;
            // }
            bool isGood = true;
            for (int sgi = 0; sgi < n; sgi++) {
                if (p[i].ss == sgi || p[j].ss == sgi) {
                    continue;
                }
                bool isSeg = isSegInter(p[i].ff, p[j].ff, l[sgi].ff, l[sgi].ss);
                if (isSeg) {
                    isGood = false;
                    break;
                }
            }
            if (isGood) dist[i][j] = (p[i].ff - p[j].ff).dist();
        }
    }

    for (int k = 0; k < n * 2 + 2; k++) {
        for (int i = 0; i < n * 2 + 2; i++) {
            for (int j = 0; j < n * 2 + 2; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << dist[0][1] << endl;

    return 0;
}
