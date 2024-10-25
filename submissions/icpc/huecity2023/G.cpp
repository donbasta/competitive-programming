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

void solve(int n) {
    vector<ll> s(n * 2 + 1), d2(n * 2 + 1), idx(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) cin >> s[i];
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin() + 1, idx.end(), [&](int a, int b) -> bool {
        return s[a] < s[b];
    });
    // debug(idx);
    sort(s.begin() + 1, s.end());

    for (int i = 3; i <= 2 * n; i++) d2[i] = s[i] - s[i - 2];

    vector<ll> dp(n * 2 + 1, INF);
    dp[0] = 0;
    dp[4] = max({d2[3], d2[4]});

    if (n >= 3) {
        dp[6] = max({d2[6], d2[5], d2[4], d2[3]});
    }

    vector<ll> prv(2 * n + 1);
    for (int i = 8; i <= 2 * n; i += 2) {
        ll A = max(d2[i - 1], d2[i]);
        ll B = max({d2[i], d2[i - 1], d2[i - 2], d2[i - 3]});
        dp[i] = min(dp[i], max(dp[i - 4], A));
        dp[i] = min(dp[i], max(dp[i - 6], B));
        if (dp[i] == max(dp[i - 4], A)) {
            prv[i] = i - 4;
        } else {
            prv[i] = i - 6;
        }
    }
    debug(dp[2 * n]);
    int cur = 2 * n;
    vector<int> A(2 * n + 1), B(2 * n + 1);
    while (cur) {
        if (prv[cur] == cur - 4) {
            A[idx[cur - 3]] = idx[cur - 2];
            A[idx[cur - 2]] = idx[cur - 3];
            A[idx[cur - 1]] = idx[cur];
            A[idx[cur]] = idx[cur - 1];

            B[idx[cur - 3]] = idx[cur - 1];
            B[idx[cur - 2]] = idx[cur];
            B[idx[cur - 1]] = idx[cur - 3];
            B[idx[cur]] = idx[cur - 2];
        } else if (prv[cur] == cur - 6) {
            A[idx[cur - 5]] = idx[cur - 4];
            A[idx[cur - 4]] = idx[cur - 5];
            A[idx[cur - 3]] = idx[cur - 1];
            A[idx[cur - 2]] = idx[cur];
            A[idx[cur - 1]] = idx[cur - 3];
            A[idx[cur]] = idx[cur - 2];

            B[idx[cur - 5]] = idx[cur - 3];
            B[idx[cur - 4]] = idx[cur - 2];
            B[idx[cur - 3]] = idx[cur - 5];
            B[idx[cur - 2]] = idx[cur - 4];
            B[idx[cur - 1]] = idx[cur];
            B[idx[cur]] = idx[cur - 1];
        }
        cur = prv[cur];
    }
    for (int i = 1; i <= n * 2; i++) {
        cout << A[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n * 2; i++) {
        cout << B[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        solve(n);
    }

    return 0;
}