#include<bits/stdc++.h>
using namespace std;

using ll = long double;
// using ld = long double;

const ll INF = 4e18;
const ll MX = LLONG_MAX;
const ll EPS = 1e-10;

inline bool eq(ll a, ll b) { return fabs(a-b) < EPS; }
inline bool lt(ll a, ll b) { return a + EPS < b; }
inline bool le(ll a, ll b) { return a < b + EPS; }
inline int sign(ll x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
    ll x,y;
    point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
    point operator*(ll t) { return point(x * t, y * t); }
    point operator/(ll t) { return point(x / t, y / t); }
    ll operator*(const point& p) const { return x * p.x + y * p.y; }
    ll operator%(const point& p) const { return x * p.y - y * p.x; }
    ll squared_norm() { return (*this) * (*this); }
    bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};

int ccw (point a, point b, point c) { return sign((b - a) % (c - b)); }
bool segaris (point a, point b, point c) {
    return ccw (a, b, c) == 0;
}

void sortCircular (vector<pair<point, ll>> &points) {
    vector<pair<point, ll>> upper, lower;
    for (auto& e : points) {
        if (point() < e.first) upper.push_back(e);
        else lower.push_back(e);
    }
    auto cmp = [](pair<point, ll> a, pair<point, ll> b) {
        int dir = sign(a.first % b.first);
        if (dir == 0)
            return a.second < b.second;
        return dir > 0;
    };
    sort (upper.begin(), upper.end(), cmp);
    sort (lower.begin(), lower.end(), cmp);
    for (int i = 0; i < (int) upper.size(); i++) points[i] = upper[i];
    for (int i = 0; i < (int) lower.size(); i++) points[i + upper.size()] = lower[i];
}

int n;
ll L, R;

void solve() {
    cin >> n >> L >> R;
    vector<point> pt(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        pt[i] = point(a, b);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        vector<pair<point, ll>> ve;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            point tmp = pt[j] - pt[i];
            ve.emplace_back(tmp, tmp.squared_norm());
        }
        sortCircular(ve);
        // cerr << i << '\n';
        // for (auto e : ve) {
        //     cerr << e.first.x << ' ' << e.first.y << '\n';
        // }
        // cout << "------\n";
        int l = 0, r = 1;
        while (l < n - 1) {
            while ((ve[l].first * ve[r].first > 0) && (ccw(point(), ve[l].first, ve[r].first) != -1)) {
                r = (r + 1) % (n - 1);
                if (r == l) break;
            }

            int find = 0;
            if ((ve[l].first * ve[r].first == 0) && (ccw(point(), ve[l].first, ve[r].first) == 1)) {
                // cerr << i << " found perpendicular\n";
                // cerr << l << ' ' << r << '\n';
                find = 1;
                vector<pair<ll, point>> A, B;
                A.emplace_back(ve[l].second, ve[l].first); 
                l++;
                B.emplace_back(ve[r].second, ve[r].first);
                r++;
                // cerr << A[0].second.x << ' ' << A[0].second.y << '\n';
                // cerr << B[0].second.x << ' ' << B[0].second.y << '\n';
                while (l < n - 1 && segaris(point(), A[0].second, ve[l].first)) {
                    A.emplace_back(ve[l].second, ve[l].first);
                    l++;
                }
                while (r < n - 1 && segaris(point(), B[0].second, ve[r].first)) {
                    B.emplace_back(ve[r].second, ve[r].first);
                    r++;
                }
                // cerr << l << ' ' << r << '\n';
                // cerr << A.size() << ' ' << B.size() << " size\n";
                for (auto& el : B) {
                    // ll kanan, kiri;
                    ll kanan = (R * R * 4) / el.first;
                    ll kiri = (L * L * 4) / el.first;
                    cur += upper_bound(A.begin(), A.end(), make_pair(floor(kanan), point(INF, INF))) - upper_bound(A.begin(), A.end(), make_pair(floor(kiri), point(INF, INF)));
                }
                // cerr << "cur: " << cur << '\n';
            }
            int tmp = l + 1;
            while (tmp < n - 1 && segaris(point(), ve[l].first, ve[tmp].first)) tmp++;
            l = tmp;
            // cerr << "----------------\n";
        }
        ans += cur;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("points.in", "r", stdin);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}