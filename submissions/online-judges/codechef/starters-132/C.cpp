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
    vector<int> ar(n), cnt1(n), cnt2(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt1[i] = (ar[i] == 1) + (i ? cnt1[i - 1] : 0);
        cnt2[i] = (ar[i] == 2) + (i ? cnt2[i - 1] : 0);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        int X = cnt1[r] - (l ? cnt1[l - 1] : 0);
        int Y = cnt2[r] - (l ? cnt2[l - 1] : 0);
        if (X > Y) swap(X, Y);
        int len = r - l + 1;
        int sisa = len - X - Y;

        ll ans;
        if (sisa >= k) {
            if (Y - X <= k) {
                int rem = k - (Y - X);
                ans = 1ll * (Y + (rem / 2)) * (Y + (rem + 1) / 2);
            } else {
                ans = 1ll * Y * (X + k);
            }
        } else {
            if (Y - X <= sisa) {
                ans = 1ll * (len / 2) * (len - (len / 2));
            } else {
                int rem = k - sisa;
                int to = min(X + sisa + rem, len / 2);
                ans = 1ll * to * (len - to);
            }
        }
        cout << ans << '\n';
    }
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