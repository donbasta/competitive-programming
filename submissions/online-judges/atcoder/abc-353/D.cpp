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
    int n;
    cin >> n;
    vector<string> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = (ans + stoll(ve[i]) * i) % MOD;
    }
    // debug(ans);

    vector<ll> cnt(11), pw10(25);
    cnt[ve[n - 1].length()]++;
    pw10[0] = 1;
    for (int i = 1; i < 25; i++) {
        pw10[i] = (pw10[i - 1] * 10) % MOD;
    }

    for (int i = n - 2; i >= 0; i--) {
        int k = ve[i].length();
        for (int j = 0; j < k; j++) {
            ll cur_dig = ve[i][j] - '0';
            for (int dig = 1; dig <= 10; dig++) {
                ll tmp = 1ll * cur_dig * pw10[dig + (k - 1 - j)] % MOD;
                tmp = (tmp * cnt[dig]) % MOD;
                ans = (ans + tmp) % MOD;
            }
        }
        cnt[ve[i].length()]++;
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