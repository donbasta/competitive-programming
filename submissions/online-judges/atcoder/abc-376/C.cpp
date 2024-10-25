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
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<bool> prf(n), suf(n);
    for (int i = 0; i < n - 1; i++) {
        prf[i] = ((B[i] >= A[i]) && (i >= 1 ? prf[i - 1] : true));
    }
    for (int i = n - 1; i > 0; i--) {
        suf[i] = ((B[i - 1] >= A[i]) && (i < n - 1 ? suf[i + 1] : true));
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        bool okl = (i >= 1 ? prf[i - 1] : true);
        bool okr = (i < n - 1 ? suf[i + 1] : true);
        if (okl && okr) {
            ans = min(ans, A[i]);
        }
    }
    if (ans == INT_MAX) {
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
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}