#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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
    bool operator==(const point& p) const { return (x == p.x) && (y == p.y); }
    bool operator<(const point& p) const { return (y == p.y) ? x < p.x : y < p.y; }
};

ll doubleAreaTriangle(point a, point b, point c) {
    return abs((a-b) % (c-b));
}

void solve() {
    int n;
    cin >> n;
    vector<point> A, B, C;
    for (int i = 0; i < n; i++) {
        int x, y;
        A.emplace_back(x, y);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        B.emplace_back(x, y);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        C.emplace_back(x, y);
    }
    vector<int> bi, ci;
    for (int i = 0; i < n; i++) {
        bi.emplace_back(i), ci.emplace_back(i);
    }
    ll ans = 1e18;

    const auto make_triple = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            vector<int> tmp = {i + 1, bi[i] + 1, ci[i] + 1};
            ret.emplace_back(tmp);
        }
        return ret;
    };

    vector<vector<int>> ret;
    do {
        iota(ci.begin(), ci.end(), 0);
        do {
            ll tmp = 0;
            for (int i = 0; i < n; i++) {
                tmp += doubleAreaTriangle(A[i], B[bi[i]], C[ci[i]]);
            }
            if (ans > tmp) {
                ret = make_triple();
                ans = tmp;
            }
        } while (next_permutation(ci.begin(), ci.end()));
    } while (next_permutation(bi.begin(), bi.end()));

    for (int i = 0; i < n; i++) {
        cout << ret[i][0] << ' ' << ret[i][1] << ' ' << ret[i][2] << '\n';
    }
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