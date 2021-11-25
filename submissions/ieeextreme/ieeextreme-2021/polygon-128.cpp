#include<bits/stdc++.h>
using namespace std;

using ll = __int128;
using ld = long double;

inline int sgn(ll x) { return (x > 0) ? 1 : (x < 0) ? -1 : 0; }

struct point {
    ll x, y, z;
    point(ll _x = 0, ll _y = 0, ll _z = 0) : x(_x), y(_y), z(_z) {}
    point operator+(const point& p) const { return point(x + p.x, y + p.y, z + p.z); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y, z - p.z); }
    point operator*(ll t) { return point(x * t, y * t, z * t); }
    ll operator*(const point& p) const { return x * p.x + y * p.y + z * p.z; }
};

ll area(const point& a, const point& b, const point& c) {
    point ab = b - a;
    point ac = c - a;
    ll u = ab.y * ac.z - ab.z * ac.y;
    ll v = ab.z * ac.x - ab.x * ac.z;
    ll w = ab.x * ac.y - ab.y * ac.x;
    // cerr << u << ' ' << v << ' ' << w << '\n';
    ll norm = u * u + v * v + w * w;
    return norm;
}

int find_ccw(const point& a, const point& b, const point& c, const point& view) {
    point ab = b - a;
    point ac = c - a;
    ll u = ab.y * ac.z - ab.z * ac.y;
    ll v = ab.z * ac.x - ab.x * ac.z;
    ll w = ab.x * ac.y - ab.y * ac.x;
    point cross = point(u, v, w);
    int dot = sgn(cross * view);
    return dot;
}

vector<ll> find_plane(const point& a, const point& b, const point& c) {
    point ab = b - a;
    point ac = c - a;
    ll u = ab.y * ac.z - ab.z * ac.y;
    ll v = ab.z * ac.x - ab.x * ac.z;
    ll w = ab.x * ac.y - ab.y * ac.x;
    long long fpb = __gcd(abs((long long)u), abs((long long)v));
    fpb = __gcd(fpb, abs((long long)w));
    return vector<ll>{u / fpb, v / fpb, w / fpb};
}

ll calc_segment(const point& a, const point& b) {
    long long dx = abs((long long) (a.x - b.x));
    long long dy = abs((long long) (a.y - b.y));
    long long dz = abs((long long) (a.z - b.z));
    long long fpb = __gcd(dx, dy);
    fpb = __gcd(fpb, dz);
    return fpb - 1;
}

ll calc_plane(const point& a, const point& b, const point& c) {
    ll A = area(a, b, c);
    if (A == 0) return 0;
    // cerr << "area: " << A << '\n';
    vector<ll> ve = find_plane(a, b, c);
    // cerr << "koefisien bidang: " << ve[0] << ' ' << ve[1] << ' ' << ve[2] << '\n';
    ll B = (ve[0] * ve[0] + ve[1] * ve[1] + ve[2] * ve[2]);
    ll C = A / B;
    C = sqrtl(C);
    ll boundary = calc_segment(a, b) + calc_segment(b, c) + calc_segment(c, a) + 3;
    ll ret = (C + 2 - boundary);
    assert (ret % 2 == 0);
    return (ret / 2);
}

void solve() {
    int n;
    cin >> n;
    vector<point> pts;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pts.emplace_back(a, b, c);
    }
    ll ans = 0;
    vector<ll> dir = find_plane(pts[0], pts[1], pts[2]);
    point arah = point(dir[0], dir[1], dir[2]);
    for (int i = 1; i < n - 1; i++) {
        dir = find_ccw(pts[0], pts[i], pts[i + 1], arah);
        assert(dir != 0);
        if (dir > 0) {
            ans += calc_plane(pts[0], pts[i], pts[i + 1]);
        } else {
            ans -= calc_plane(pts[0], pts[i], pts[i + 1]);
        }
        ans += calc_plane(pts[0], pts[i], pts[i + 1]);
    }
    for (int i = 2; i < n - 1; i++) {
        ans += calc_segment(pts[0], pts[i]);
    }
    long long ret = (long long) ans;
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}