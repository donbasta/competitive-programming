#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return false;
        }
        if (x->k == y->k) {
            x->p = (x->m > y->m) ? inf : -inf;
        } else {
            x->p = div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) {
            z = erase(z);
        }
        if (x != begin() && isect(--x, y)) {
            isect(x, y = erase(y));
        }
        while ((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

const int N = 1e6;

ll ar[N + 5], pre[N + 5], dp[N + 5];

inline ll sq(ll x) { return x * x; }
inline ll f(ll a, ll b, ll c, ll x) { return a * sq(x) + b * x + c; }

void solve() {
    int n;
    ll a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }

    LineContainer cht;
    dp[0] = 0;
    cht.add(a * pre[0] * (-2), dp[0] + a * sq(pre[0]) - b * pre[0]);
    for (int i = 1; i <= n; i++) {
        dp[i] = f(a, b, c, pre[i]) + cht.query(pre[i]);
        cht.add(a * pre[i] * (-2), dp[i] + a * sq(pre[i]) - b * pre[i]);
    }
    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}