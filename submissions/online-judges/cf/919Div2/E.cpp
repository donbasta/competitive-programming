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

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp1(n + 1, vector<int>(k)), dp2(n + 1, vector<int>(k));

    for (int i = 0; i < k; i++) dp2[0][i] = 1;
    dp1[0][0] = 1;
    for (int i = 0; i < k; i++) dp1[i + 1][i] = 1;

    int ap = 0;
    for (int i = 0; i < k; i++) add(ap, dp1[0][i]);

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s < k; s++) {
            int r = 0;
            while ((r + s <= k - 1) && ((r + 1) * s < i)) {
                add(dp2[i][s], dp1[i - (r + 1) * s][r]);
                r++;
            }
        }
        for (int s = 0; s < k; s++) {
            if (s == 0) {
                dp1[i][s] = ap;  //=dp1[i-1][0] + ... + dp1[i-1][k-1]
            } else {
                if (i >= s + 1) dp1[i][s] = dp2[i - s - 1][s];
            }
        }
        ap = 0;
        for (int s = 0; s < k; s++) add(ap, dp1[i][s]);
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
        add(ans, dp1[n][i]);
        if (i > 0) add(ans, dp2[n][i]);
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