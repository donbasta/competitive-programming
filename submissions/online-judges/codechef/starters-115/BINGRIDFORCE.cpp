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
const ll MOD = 1e9 + 7;
const int M = 1e6;

ll fc[M + 5], ifc[M + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init() {
    fc[0] = 1;
    for (int i = 1; i <= M; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[M] = fpow(fc[M], MOD - 2);
    for (int i = M - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return (fc[a] * ifc[b]) % MOD * ifc[a - b] % MOD;
}

struct DSU {
    vector<int> par;
    int n;
    DSU(int n) : n(n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    void reset() {
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        par[x] = y;
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<string> L(n);
    vector<vector<vector<int>>> pos(n, vector<vector<int>>(2));
    for (int i = 0; i < n; i++) {
        cin >> L[i];
        for (int j = 0; j < m; j++) {
            pos[i][L[i][j] - '0'].push_back(j);
        }
    }
    DSU dsu(m);
    for (int i = n - 1; i >= 1; i--) {
        if (pos[i][1].size() <= 1) {
            dsu.reset();
        } else {
            int cur = pos[i][1][0];
            for (int j = 1; j < pos[i][1].size(); j++) {
                dsu.merge(cur, pos[i][1][j]);
            }
            int x = dsu.fpar(cur);
            for (int j = 0; j < pos[i][0].size(); j++) {
                if (dsu.fpar(pos[i][0][j]) != x) {
                    dsu.par[pos[i][0][j]] = pos[i][0][j];
                }
            }
        }
    }
    vector<int> sz(m), cnt1(m);
    for (int i = 0; i < m; i++) {
        sz[dsu.fpar(i)]++;
        cnt1[dsu.fpar(i)] += (L[0][i] == '1');
    }
    debug(sz, cnt1);
    ll ans = 1;
    for (int i = 0; i < m; i++) {
        if (sz[i] <= 1) continue;
        ans = (ans * C(sz[i], cnt1[i])) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}