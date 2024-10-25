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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, INF));
    dp[0][0] = 0;
    for (int i = 2; i < 2 * n; i += 2) {
        if (grid[i % n][0] != 1 && grid[(i - 1) % n][0] != 1) {
            dp[i % n][0] = min(dp[i % n][0], i / 2);
        } else {
            break;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == 1) continue;
            dp[j][i] = min(dp[j][i], dp[(j + n - 1) % n][i - 1] + 1);
        }
        for (int t = 0; t < 2; t++) {
            int cur = t + 2, prv = t;
            for (int x = 0; x < 2 * n; x++) {
                if (grid[cur % n][i] != 1 && grid[(cur - 1) % n][i] != 1) {
                    dp[cur % n][i] = min(dp[cur % n][i], (cur - prv) / 2 + dp[prv % n][i]);
                    if (dp[cur % n][i] < (cur - prv) / 2 + dp[prv % n][i]) {
                        prv = cur;
                    }
                } else {
                    if (grid[cur % n][i] != 1)
                        prv = cur;
                    else
                        prv = cur + 2;
                }
                cur += 2;
            }
        }
    }

    // debug(dp);

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll tmp = dp[i][m - 1];
        if (tmp == INF) continue;
        ll ril = (i - tmp) % n;
        if (ril < 0) ril += n;
        ll cur = tmp + min(n - 1 - ril, ril + 1);
        ans = min(ans, cur);
    }
    if (ans == INF) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
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