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

void el_psy_congroo() {
    ll m, x;
    cin >> m >> x;
    vector<ll> C(m), H(m);
    ll tot_hap = 0;
    for (int i = 0; i < m; i++) {
        cin >> C[i] >> H[i];
        tot_hap += H[i];
    }
    // dp[i][h] = x + (dp[i - 1][h - H[i]] for all s.t. dp[i - 1][h - H[i]] >= C[i])
    vector<vector<ll>> dp(m, vector<ll>(tot_hap + 1, -1));
    dp[0][0] = x;
    if (C[0] == 0) dp[0][H[0]] = x;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= tot_hap; j++) {
            if (dp[i - 1][j] >= 0) dp[i][j] = max(dp[i][j], x + dp[i - 1][j]);
            if (j >= H[i] && dp[i - 1][j - H[i]] >= C[i]) {
                dp[i][j] = max(dp[i][j], x + dp[i - 1][j - H[i]] - C[i]);
            }
        }
    }
    for (int i = tot_hap; i >= 0; i--) {
        if (dp[m - 1][i] >= 0) {
            cout << i << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}