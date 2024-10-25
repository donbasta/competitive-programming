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
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ar[i] %= 2;
    }
    vector<pair<int, int>> segs;
    int st = -1;
    for (int i = 0; i < n; i++) {
        if (ar[i] == 1) {
            if (st == -1) st = i;
        } else {
            if (st != -1) {
                segs.emplace_back(st, i - 1);
                st = -1;
            }
        }
    }
    if (st != -1) segs.emplace_back(st, n - 1);

    ll all = 1ll * n * (n + 1) / 2;
    for (auto se : segs) {
        ll len = se.second - se.first + 1;
        all -= len * (len + 1) / 2;
    }
    ll ret = all;

    for (int i = 0; i < n; i++) {
        if (ar[i] == 0) continue;
        int x = lower_bound(segs.begin(), segs.end(), make_pair(i + 1, -1)) - segs.begin();
        assert(x > 0);
        --x;
        ll L = segs[x].first, R = segs[x].second;
        ll ki = i - L, ka = R - i, tot = R - L + 1;
        ret = max(ret, all + tot * (tot + 1) / 2 - ki * (ki + 1) / 2 - ka * (ka + 1) / 2);
    }

    cout << ret << '\n';
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