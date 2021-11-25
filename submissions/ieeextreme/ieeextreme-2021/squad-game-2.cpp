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
};

ll doubleAreaTriangle(point a, point b, point c) {
    return abs((a-b) % (c-b));
}

void solve() {
    int n;
    cin >> n;
    vector<pair<point, int>> A, B, C;
    for (int i = 0; i < n; i++) {
        int x, y;
        A.emplace_back(point(x, y), i);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        B.emplace_back(point(x, y), i);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        C.emplace_back(point(x, y), i);
    }

    auto sortVertikal = [](const pair<point, int>& a, const pair<point, int>& b) -> bool {
        return (a.first.y == b.first.y) ? a.first.x < b.first.x : a.first.y < b.first.y;
    };
    auto sortHorizontal = [](const pair<point, int>& a, const pair<point, int>& b) -> bool {
        return (a.first.x == b.first.x) ? a.first.y < b.first.y : a.first.x < b.first.x;
    };

    const auto hitungArea = [&]() -> ll {
        ll area = 0;
        for (int i = 0; i < n; i++) {
            area += doubleAreaTriangle(A[i].first, B[i].first, C[i].first);
        }
        return area;
    };

    sort(A.begin(), A.end(), sortHorizontal);
    sort(B.begin(), B.end(), sortHorizontal);
    sort(C.begin(), C.end(), sortHorizontal);

    ll H = hitungArea();

    sort(A.begin(), A.end(), sortVertikal);
    sort(B.begin(), B.end(), sortVertikal);
    sort(C.begin(), C.end(), sortVertikal);

    ll V = hitungArea();

    if (H < V) {
        sort(A.begin(), A.end(), sortHorizontal);
        sort(B.begin(), B.end(), sortHorizontal);
        sort(C.begin(), C.end(), sortHorizontal);
    }

    const auto make_triple = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            vector<int> tmp = {A[i].second + 1, B[i].second + 1, C[i].second + 1};
            ret.emplace_back(tmp);
        }
        return ret;
    };

    vector<vector<int>> ret = make_triple();

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