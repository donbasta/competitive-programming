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
const int B = 500;
const int N = 3e5;
const ll MOD = 998244353;

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
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    return ((fc[a] * ifc[b]) % MOD) * ifc[a - b] % MOD;
}

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> A(n), B(n), PA(n), PB(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) {
        PA[i] = A[i] + (i ? PA[i - 1] : 0);
        PB[i] = B[i] + (i ? PB[i - 1] : 0);
    }
    ll i2 = fpow(2, MOD - 2);
    ll aB = PB[n - 1];
    ll denom = fpow(i2, aB);
    while (q--) {
        int l, r;
        cin >> l >> r;
        --r, --l;
        if (r == n - 1 && l == 0) {
            cout << 1 << '\n';
            continue;
        }
        ll Y = PB[r] - (l ? PB[l - 1] : 0);
        ll X = PA[n - 1] - 2ll * (PA[r] - (l ? PA[l - 1] : 0));
        ll prob = 0, tmp = 0;
        for (int i = max(0ll, X + 1); i <= Y; i++) {
            tmp = (tmp + C(aB - Y, i - X - 1)) % MOD;
            prob = (prob + C(Y, i) * tmp) % MOD;
        }
        prob = (prob * denom) % MOD;
        cout << prob << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init_fac();

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}