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

const int INF = 2e9;

struct DSU {
    int n;
    vector<ll> par, sz;
    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) { return (x == par[x]) ? x : par[x] = fpar(par[x]); }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        par[x] = y;
        sz[y] += sz[x];
    }
};

void el_psy_congroo() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> ve;
    for (int i = 0; i < m; i++) {
        ll k, c;
        cin >> k >> c;
        vector<ll> tmp;
        tmp.push_back(c);
        for (int j = 0; j < k; j++) {
            ll a;
            cin >> a;
            tmp.push_back(a);
        }
        ve.push_back(tmp);
    }
    sort(ve.begin(), ve.end());
    ll mst = 0;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        ll cost = ve[i][0];
        ll i1 = ve[i][1];
        for (int j = 2; j < (int)ve[i].size(); j++) {
            if (dsu.fpar(i1) == dsu.fpar(ve[i][j])) continue;
            dsu.merge(i1, ve[i][j]);
            mst += cost;
        }
    }
    if (dsu.sz[dsu.fpar(0)] != n) {
        cout << -1 << '\n';
    } else {
        cout << mst << '\n';
    }
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