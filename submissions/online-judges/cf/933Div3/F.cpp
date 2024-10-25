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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n), D(m), F(k), dif(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> D[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> F[i];
    }
    sort(D.begin(), D.end());
    sort(F.begin(), F.end());

    ll mx = -1;
    for (int i = 0; i < n - 1; i++) {
        dif[i] = A[i + 1] - A[i];
        mx = max(mx, dif[i]);
    }
    int cnt_max = 0, pos = -1;
    for (int i = 0; i < n - 1; i++) {
        if (dif[i] == mx) {
            cnt_max++;
            pos = i;
        }
    }
    assert(pos != -1);
    ll ans = mx;
    if (cnt_max == 1) {
        ll other_mx = -1;
        for (int i = 0; i < n - 1; i++) {
            if (dif[i] != mx) other_mx = max(other_mx, dif[i]);
        }
        ll mid = (A[pos] + A[pos + 1]) / 2;
        for (int i = 0; i < m; i++) {
            int idx = upper_bound(F.begin(), F.end(), mid - D[i]) - F.begin() - 1;
            if ((idx >= 0) && (D[i] + F[idx] >= A[pos])) {
                ans = min(ans, max({D[i] + F[idx] - A[pos], A[pos + 1] - D[i] - F[idx], other_mx}));
            }
            if ((idx + 1 < k) && (D[i] + F[idx + 1] <= A[pos + 1])) {
                ans = min(ans, max({D[i] + F[idx + 1] - A[pos], A[pos + 1] - D[i] - F[idx + 1], other_mx}));
            }
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