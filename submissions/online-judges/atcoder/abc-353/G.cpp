#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tc template <class
tc T1, class T2 > ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
tc T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t < !is_same<T, string>::value >> ostream &operator<<(ostream &os, const T &c) {
    os << '{';
    for (auto it = c.begin(); it != c.end(); ++it) os << &", "[2 * (it == c.begin())] << *it;
    return os << '}';
}
#define PARENS ()
#define EEE(...) EEE1(EEE1(__VA_ARGS__))
#define EEE1(...) EEE2(__VA_ARGS__)
#define EEE2(...) __VA_ARGS__
#define REP(macro, ...) __VA_OPT__(EEE(REP_HELPER(macro, __VA_ARGS__)))
#define REP_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(REP_AGAIN PARENS(macro, __VA_ARGS__))
#define REP_AGAIN() REP_HELPER
#define out(x) "\t[" << #x " = " << x << "]\n"
#ifdef LOCAL
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP(out, __VA_ARGS__) << "\n";
#else
#define debug(...) "itfeelsliketimeispassingsoquickly.thepassageoftimedependsentirelyonwhereyou'restanding.relativitytheory...it'ssoromantic.butit'sjustsotragictoo."
#endif

const ll INF = 1e18 + 69;  // LLONG_MAX

struct line {
    mutable ll k, m, p;
    bool operator<(const line &other) const {
        return k < other.k;
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

struct Segtree {
    vector<lineContainer> ve;
    int n;
    Segtree(int n) : n(n), ve(4 * n + 5) {}

    void add_line(int v, int s, int e, int idx, ll M, ll C) {
        if (s == e) {
            ve[v].add(M, C);
            return;
        }
        int mid = (s + e) >> 1;
        ve[v].add(M, C);
        if (idx <= mid)
            add_line(v << 1, s, mid, idx, M, C);
        else
            add_line(v << 1 | 1, mid + 1, e, idx, M, C);
    }

    void add_line(int idx, ll M, ll C) {  // add y = Mx + C
        add_line(1, 0, n - 1, idx, M, C);
    }

    ll query(int v, int s, int e, int l, int r, ll X) {
        if (s == l && e == r) return ve[v].query(X);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return query(v << 1, s, mid, l, r, X);
        } else if (l >= mid + 1) {
            return query(v << 1 | 1, mid + 1, e, l, r, X);
        } else {
            return max(query(v << 1, s, mid, l, mid, X), query(v << 1 | 1, mid + 1, e, mid + 1, r, X));
        }
    }

    ll query(int l, int r, ll X) {  // query max di X
        return query(1, 0, n - 1, l, r, X);
    }
};

void el_psy_congroo() {
    ll n, c, m;
    cin >> n >> c >> m;
    vector<ll> F(n, -INF);
    F[0] = 0;

    Segtree s1(n), s2(n);
    for (int i = 0; i < n; i++) {
        s1.add_line(i, -c, c * i + F[i]);
        s2.add_line(i, c, F[i] - c * i);
    }

    ll ans = 0;

    for (int i = 0; i < m; i++) {
        ll t, p;
        cin >> t >> p;
        --t;
        ll mx = -INF;
        mx = max(mx, s1.query(0, t, t));
        mx = max(mx, s2.query(t, n - 1, t));
        // debug(i, mx);
        ll new_ft = p + mx;
        ans = max(ans, new_ft);

        // debug(ans);

        if (new_ft > F[t]) {
            F[t] = new_ft;
            s1.add_line(t, -c, c * t + new_ft);
            s2.add_line(t, c, new_ft - c * t);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}