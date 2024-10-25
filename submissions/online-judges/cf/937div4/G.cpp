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
    int n;
    cin >> n;
    vector<string> g(n), w(n);
    for (int i = 0; i < n; i++) cin >> g[i] >> w[i];
    vector<vector<bool>> con(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i] == g[j] || w[i] == w[j]) {
                con[i][j] = con[j][i] = true;
            }
        }
    }
    vector<vector<bool>> dp(1 << n, vector<bool>(n));

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if (!((mask >> j) & 1)) continue;
            if (__builtin_popcount(mask) == 1) {
                dp[mask][j] = true;
                break;
            }
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                if (!con[k][j]) continue;
                if (!((mask >> k) & 1)) continue;
                dp[mask][j] = (dp[mask][j] || (dp[mask ^ (1 << j)][k]));
            }
        }
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            // cout << mask << ' ' << j << ' ' << dp[mask][j] << '\n';
            if (dp[mask][j]) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
    }
    cout << (n - ans) << '\n';
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