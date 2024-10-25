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
    string s;
    cin >> s;

    int dp[n][2] = {0};
    int x1 = 0, y1 = -1;
    int x2 = 0, y2 = -1;
    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        if (i > y1) {
            k = 1;
        } else {
            k = min(dp[x1 + y1 - i][0], y1 - i + 1);
        }
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        dp[i][0] = k--;
        if (i + k > y1) x1 = i - k, y1 = i + k;
        if (2 * dp[i][0] - 1 > mx) ans = i - k, mx = 2 * dp[i][0] - 1;
        k = 0;
        if (i <= y2) k = min(dp[x2 + y2 - i + 1][1], y2 - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        dp[i][1] = k--;
        if (i + k > y2) x2 = i - k - 1, y2 = i + k;
        if (2 * dp[i][1] > mx) ans = i - k - 1, mx = 2 * dp[i][1];
    }
    cout << mx << '\n';
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