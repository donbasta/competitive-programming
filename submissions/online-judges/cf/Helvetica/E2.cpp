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

using matrix = vector<vector<ll>>;

matrix ID;

matrix mul(matrix a, matrix b) {
    int sz = (int)a.size();
    matrix d(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return d;
}

matrix fpow(matrix a, ll b) {
    matrix ret = ID;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    ll m, n;
    cin >> m >> n;
    vector<ll> S(m), L(m), T(m);
    for (int i = 0; i < m; i++) cin >> S[i];
    for (int i = 0; i < m; i++) cin >> L[i];
    for (int i = 0; i < m; i++) T[i] = S[i] + L[i];

    matrix M(m, vector<ll>(m));
    for (int i = 0; i < m; i++) {
        vector<ll> tmp(m);
        tmp[i] = 1;
        ID.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = (T[i] * T[j] - L[i] * L[j]) % MOD;
        }
    }

    matrix Mpw = fpow(M, n);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans = (ans + Mpw[i][0]) % MOD;
    }
    if (ans < 0) ans += MOD;
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