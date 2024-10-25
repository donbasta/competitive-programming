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

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    ll n, p, k;
    cin >> n >> p >> k;
    ll pn = fpow(p, n);
    ll ip = fpow(p, MOD - 2);
    vector<ll> pw(k + 1), ipw(k + 1);
    pw[0] = 1;
    ipw[0] = 1;
    for (int i = 1; i <= k; i++) {
        pw[i] = pw[i - 1] * p % MOD;
        ipw[i] = ipw[i - 1] * ip % MOD;
    }
    vector<ll> pre(k + 1), ipre(k + 1);
    pre[0] = 1;
    ipre[0] = 1;
    for (int i = 1; i <= k; i++) {
        pre[i] = pre[i - 1] * (pn - pw[i - 1]) % MOD;
        if (pre[i] < 0) pre[i] += MOD;
        ipre[i] = ipre[i - 1] * (pw[i] - 1) % MOD;
        if (ipre[i] < 0) ipre[i] += MOD;
    }
    vector<ll> ans(k + 1);
    ans[0] = 1;
    ll tmp = 1;
    for (int i = 1; i <= k; i++) {
        ans[i] = pre[i] * pre[i] % MOD;
        ans[i] = ans[i] * tmp % MOD;
        tmp = tmp * ipw[i] % MOD;
        // ans[i] = ans[i] * fpow(ip, i * (i - 1) / 2) % MOD;
        ans[i] = ans[i] * fpow(ipre[i], MOD - 2) % MOD;
        if (ans[i] < 0) ans[i] += MOD;
    }
    debug(pre, ipre);
    for (int i = 0; i <= k; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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