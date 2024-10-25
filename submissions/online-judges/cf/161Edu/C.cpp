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
    vector<ll> ar(n), ri(n), le(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            ri[i] = 1;
            continue;
        }
        if (ar[i + 1] - ar[i] < ar[i] - ar[i - 1]) {
            ri[i] = 1;
        } else {
            ri[i] = ar[i + 1] - ar[i];
        }
    }
    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            le[i] = 1;
            continue;
        }
        if (ar[i + 1] - ar[i] < ar[i] - ar[i - 1]) {
            le[i] = ar[i] - ar[i - 1];
        } else {
            le[i] = 1;
        }
    }
    vector<ll> pri(n), ple(n);
    for (int i = 0; i < n; i++) {
        pri[i] = ri[i] + (i ? pri[i - 1] : 0);
        ple[i] = le[i] + (i ? ple[i - 1] : 0);
    }
    // debug(le, ri);
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        ll ans;
        if (x < y) {
            ans = pri[y - 1] - (x ? pri[x - 1] : 0);
        } else {
            ans = ple[x] - ple[y];
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