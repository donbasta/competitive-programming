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
const int MOD = 998244353;
const int N = 1e6;

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

void init() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) fc[i] = (fc[i - 1] * i) % MOD;
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a] * ifc[b] % MOD;
    return (ret * ifc[a - b]) % MOD;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    for (int k = 1; k <= (n - 1) / 2; k++) {
        ll ans = 1;
        for (int x = 1; x * 2 * k <= n; x++) {
            ans = (ans + C(n, 2 * x * k)) % MOD;
            ans = (ans - C(n - 2 * x * k + 2 * k - 1, 2 * k - 1)) % MOD;
        }
        if (ans < 0) ans += MOD;
        cout << ans << ' ';
    }
    cout << '\n';
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