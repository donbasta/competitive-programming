#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18 + 69;  // LLONG_MAX

struct line {
    ll k, m, p;
    bool operator<(const line &other) const {
        return k < o.k;
    }
    bool operator<(ll x) const {
        return p < x;
    }
};

struct lineContainer : multiset<line, less<>> {
    ll div(ll a, ll b) {  // floored division for negative as well
        return a / b - ((a ^ b) < 0 && (a % b));
    }
    bool intersect(iterator x, iterator y) {
        if (y == end()) {
            x->p = INF;
            return false;
        }
        if (x->k == y->k) {
            x->p = (x->m > y->m ? INF : -INF);
        } else {
            x->p = div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}),
             y = z++, x = y;
        while (intersect(y, z))
            z = erase(z);
        if (x != begin() && intersect(--x, y))
            intersect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            intersect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j <= m; j++) {
            if (s[j] == '1') {
                v.emplace_back(i, j);
            }
        }
    }
    ll ans = 0;
    KDTree tree(v);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ans += tree.nearest(Point<ll>(i, j)).first;
        }
    }
    cout << ans << '\n';
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