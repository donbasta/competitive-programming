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
    vector<int> ve(n + 1), F(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if ((ve[i] >= i) && ((ve[i] - i) % 2 == 0)) {
            F[i] = (ve[i] - i) / 2;
        }
    }
    const ll INF = 2e9;
    vector<vector<bool>> P(n + 1, vector<bool>(n + 1));
    vector<vector<ll>> mn_right(n + 1, vector<ll>(n + 1, INF));
    // P[i][j] --> until index j, take j pairs
    for (int i = 1; i <= n; i++) P[i][0] = true;
    for (int i = 1; i <= n - 1; i++) {
        if (F[i] == 0) {
            P[i][1] = true;
            mn_right[i][1] = i + 1;
        }
    }
    for (ll i = 2; i <= n - 1; i++) {
        // if (i >= 2) {
        for (ll j = 2; j <= n; j++) {
            P[i][j] = P[i - 1][j];
            if (P[i][j]) mn_right[i][j] = mn_right[i - 1][j];
        }
        if (F[i] != -1) {
            for (int j = F[i]; j <= n - 1; j++) {
                ll kan = max(mn_right[i - 2][j], i - 1);
                if ((P[i - 2][j]) && (kan + 2 <= n)) {
                    P[i][j + 1] = true;
                    mn_right[i][j + 1] = min(mn_right[i][j + 1], kan + 2);
                }
            }
            if ((F[i - 1] >= F[i])) {
                for (int j = F[i - 1]; j <= n - 1; j++) {
                    ll kan = max(mn_right[i - 1][j], i - 1);
                    if ((P[i - 1][j]) && (kan + 2 <= n)) {
                        P[i][j + 1] = true;
                        mn_right[i][j + 1] = min(mn_right[i][j + 1], kan + 2);
                    }
                }
            }
        }
        // }
    }
    int ans = 0;
    // debug(P[5]);
    // debug(mn_suf[5]);

    // debug(P[6]);
    // debug(mn_suf[6]);

    // debug(P[4]);
    // debug(mn_suf[4]);
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= n; j++) {
            if (P[i][j]) ans = max(ans, j);
        }
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