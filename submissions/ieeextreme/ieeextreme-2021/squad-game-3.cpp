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
    vector<vector<vector<ll>>> areas(n, vector<vector<ll>>(n, vector<ll>(n)));
    vector<pair<ll, vector<int>>> lol;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                areas[i][j][k] = doubleAreaTriangle(A[i], B[j], C[k]);
                lol.emplace_back(areas[i][j][k], vector<int>{i, j, k});
            }
        }
    }
    sort(lol.begin(), lol.end());

    vector<vector<int>> ret;
    int need = n;
    vector<bool> ua(n), ub(n), uc(n);
    int idx = 0;
    while (need) {
        if (ua[lol[idx].second[0]] || ub[lol[idx].second[1]] || uc[lol[idx].second[2]]) {
            idx++;
            continue;
        }
        ua[lol[idx].second[0]] = true, ub[lol[idx].second[1]] = true, uc[lol[idx].second[2]] = true;
        ret.emplace_back(lol[idx].second);
        idx++;
        need--;
    }

    for (int i = 0; i < n; i++) {
        cout << ret[i][0] + 1 << ' ' << ret[i][1] + 1 << ' ' << ret[i][2] + 1 << '\n';
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