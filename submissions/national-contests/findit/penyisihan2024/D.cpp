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
    vector<ll> W(n), PW(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < n; i++) {
        PW[i] = W[i] + (i ? PW[i - 1] : 0);
    }

    auto sum = [&](ll a, ll b) -> ll {
        return PW[b] - (a ? PW[a - 1] : 0);
    };

    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    const int B = 3;
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            int l = i, r = j - 1, piv = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sum(i, mid) >= sum(mid + 1, j)) {
                    r = mid - 1;
                } else {
                    piv = mid;
                    l = mid + 1;
                }
            }

            if (piv == -1) piv = i - 1;
            for (int k = max(i, piv - B); k <= min(j - 1, piv + B); k++) {
                if (sum(i, k) == sum(k + 1, j)) {
                    dp[i][j] = max(dp[i][j], sum(i, k) + max(dp[i][k], dp[k + 1][j]));
                } else if (sum(i, k) < sum(k + 1, j)) {
                    dp[i][j] = max(dp[i][j], sum(i, k) + dp[i][k]);
                } else if (sum(i, k) > sum(k + 1, j)) {
                    dp[i][j] = max(dp[i][j], sum(k + 1, j) + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
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