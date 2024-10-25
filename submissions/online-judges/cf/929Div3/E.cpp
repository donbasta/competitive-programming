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

const ll INF = 1e18 + 69;  // LLONG_MAX

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    vector<ll> P(n);
    for (int i = 0; i < n; i++) {
        P[i] = ar[i] + (i ? P[i - 1] : 0);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll L, U;
        cin >> L >> U;
        --L;
        if (ar[L] > U) {
            cout << (L + 1) << ' ';
            continue;
        }
        ll l = L, r = n - 1, piv = -1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll tot = P[mid] - (L ? P[L - 1] : 0);
            if (tot <= U) {
                piv = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // ar[L] + ... ar[piv] <= U
        ll ans = piv + 1;
        if (piv + 1 < n) {
            ll a = P[piv] - (L ? P[L - 1] : 0);
            ll b = P[piv + 1] - (L ? P[L - 1] : 0);
            if (a * (U * 2 + 1 - a) < b * (U * 2 + 1 - b)) {
                ans++;
            }
        }
        cout << ans << ' ';
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