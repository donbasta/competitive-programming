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
const ll MOD = 998244353;

void el_psy_congroo() {
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> x(q), y(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
    }
    map<int, int> lr, lc;
    vector<int> cc(q + 1), cr(q + 1);
    for (int i = 0; i < q; i++) {
        lr[x[i]] = i, lc[y[i]] = i;
    }
    set<int> sc, sr;
    for (int i = q - 1; i >= 0; i--) {
        sc.insert(y[i]), sr.insert(x[i]);
        cc[i] = sc.size(), cr[i] = sr.size();
    }
    ll ans = 1;
    for (int i = 0; i < q; i++) {
        bool ok = (lr[x[i]] == i && cc[i + 1] < m) || (lc[y[i]] == i && cr[i + 1] < n);
        if (ok) {
            ans = (ans * k) % MOD;
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