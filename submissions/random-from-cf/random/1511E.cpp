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

const ll MOD = 998244353;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<string> ve(n);
    for (int i = 0; i < n; i++) cin >> ve[i];
    ll w = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            w += ve[i][j] == 'o';
        }
    }
    vector<ll> pw(m * n + 1), pre(m * n + 1);
    pw[0] = 1;
    for (int i = 1; i <= m * n; i++) {
        pw[i] = (pw[i - 1] * 2) % MOD;
    }
    pre[0] = pw[0];
    pre[1] = pw[1];
    for (int i = 2; i <= m * n; i++) {
        pre[i] = (pre[i - 2] + pw[i]) % MOD;
    }

    auto F = [&](ll a, ll b) -> ll {
        assert((a % 2) == (b % 2));
        ll ret = (pre[b] - (a >= 2 ? pre[a - 2] : 0)) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    };

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int awal = -1;
        for (int j = 0; j < m; j++) {
            if (ve[i][j] == '*') continue;
            if (j == 0 || ve[i][j - 1] == '*') awal = j;
            if (j < m - 1 && ve[i][j + 1] == 'o') {
                if (j % 2 == awal % 2) {
                    ll x = (j - awal + 2) / 2;
                    ans = (ans + F(w - x * 2 + 1, w - 3)) % MOD;
                    ans = (ans + pw[w - x * 2]) % MOD;
                } else {
                    ll x = (j - awal + 1) / 2;
                    ans = (ans + F(w - 1 - x * 2, w - 3)) % MOD;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int awal = -1;
        for (int j = 0; j < n; j++) {
            if (ve[j][i] == '*') continue;
            if (j == 0 || ve[j - 1][i] == '*') awal = j;
            if (j < n - 1 && ve[j + 1][i] == 'o') {
                if (j % 2 == awal % 2) {
                    ll x = (j - awal + 2) / 2;
                    ans = (ans + F(w - x * 2 + 1, w - 3)) % MOD;
                    ans = (ans + pw[w - x * 2]) % MOD;
                } else {
                    ll x = (j - awal + 1) / 2;
                    ans = (ans + F(w - 1 - x * 2, w - 3)) % MOD;
                }
            }
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}