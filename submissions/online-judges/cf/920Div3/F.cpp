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
const int B = 450;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<vector<ll>> X(B + 1, vector<ll>(n));
    vector<vector<ll>> Y(B + 1, vector<ll>(n));
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < n; j++) {
            X[i][j] = A[j] + (j >= i ? X[i][j - i] : 0);
        }
        for (int j = 0; j < n; j++) {
            Y[i][j] = X[i][j] + (j >= i ? Y[i][j - i] : 0);
        }
    }

    while (q--) {
        int s, d, k;
        cin >> s >> d >> k;
        --s;
        if (d <= B) {
            ll ans = 1ll * k * X[d][s + d * (k - 1)];
            if (s + d * (k - 2) >= 0) ans -= Y[d][s + d * (k - 2)];
            if (s - d * 2 >= 0) ans += Y[d][s - d * 2];
            cout << ans << ' ';
        } else {
            assert(k <= B);
            int cur = s, mul = 1;
            ll ans = 0;
            while (mul <= k) {
                ans += A[cur] * mul;
                cur += d, mul++;
            }
            cout << ans << ' ';
        }
    }
    cout << '\n';
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