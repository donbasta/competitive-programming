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
const int N = 2e5;

ll fc[N + 5], ifc[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) fc[i] = (fc[i - 1] * i) % MOD;
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
}

void el_psy_congroo() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll ans = 0;
    if (k >= n) {
        for (int i = 1; i <= n; i++) {
            ll tmp = fpow(m - 1, i - 1) * fpow(m, n - i) % MOD;
            ans = (ans + tmp) % MOD;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            ll tmp = fpow(k - 1, n - i) * fc[n] % MOD;
            tmp = (tmp * ifc[i]) % MOD;
            tmp = (tmp * ifc[n - i]) % MOD;

            ll sel;
            if (i >= k) {
                sel = (fpow(m - k + 1, i) - fpow(m - k, k) * fpow(m - k + 1, i - k)) % MOD;
            } else {
                sel = (fpow(m - k + 1, i) - fpow(m - k, i)) % MOD;
            }
            tmp = (tmp * sel) % MOD;
            ans = (ans + tmp) % MOD;
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init_fac();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}