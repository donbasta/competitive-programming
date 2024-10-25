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
#define LOG(...) cerr << "Line " << __LINE__ << "\n" \
                      << REP(out, __VA_ARGS__) << "\n";

const int INF = 2e9;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> p(n), pw(n);
    bool sq = true;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> pw[i];
        sq &= (pw[i] % 2 == 0);
    }
    ll N = 1, ND = 1, SD = 1, PD;
    for (int i = 0; i < n; i++) {
        N = N * fpow(p[i], pw[i]) % MOD;
        ND = ND * (pw[i] + 1) % MOD;
        SD = SD * (fpow(p[i], pw[i] + 1) - 1) % MOD;
        SD = SD * (fpow(p[i] - 1, MOD - 2)) % MOD;
    }
    if (sq) {
        ll sqN = 1;
        for (int i = 0; i < n; i++) {
            sqN = sqN * fpow(p[i], pw[i] / 2) % MOD;
        }
        ll tmp = 1;
        for (int i = 0; i < n; i++) {
            tmp = tmp * (pw[i] + 1) % (MOD - 1);
        }
        PD = fpow(sqN, tmp);
    } else {
        ll tmp = 1, done = false;
        for (int i = 0; i < n; i++) {
            if (pw[i] % 2 == 1 && (!done)) {
                tmp = tmp * ((pw[i] + 1) / 2) % (MOD - 1);
                done = true;
            } else {
                tmp = tmp * (pw[i] + 1) % (MOD - 1);
            }
        }
        PD = fpow(N, tmp);
    }

    LOG(ND, PD, SD);

    if (ND < 0) ND += MOD;
    if (SD < 0) SD += MOD;
    if (PD < 0) PD += MOD;
    cout << ND << ' ' << SD << ' ' << PD << '\n';
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