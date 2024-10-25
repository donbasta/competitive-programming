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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];

    // find max size subset of indices T s.t. sum(a_t) <= x, sum(b_t) <= y

    const ll INF = 2e9;
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n + 1, vector<ll>(x + 1, INF)));
    // dp[i][j][k] --> ampe indeks i, ambil j buah food dengan sum a = k, sum b minimal = ...

    // dp[i][j][k]
    //     --> dp[i - 1][j - 1][k - a[i]] + b[i]
    //     --> dp[i - 1][j][k]

    dp[0][0][0] = 0;
    if (A[0] <= x) dp[0][1][A[0]] = B[0];

    for (int i = 1; i < n; i++) {
        dp[i][0][0] = 0;
        for (int j = 1; j <= i + 1; j++) {
            for (int k = 0; k <= x; k++) {
                if (k >= A[i]) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - A[i]] + B[i]);
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[n - 1][i][j] <= y) ans = max(ans, i);
        }
    }
    cout << min(n, (1ll * ans + 1)) << '\n';
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