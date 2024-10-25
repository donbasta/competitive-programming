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
    ll m, x;
    cin >> m >> x;
    vector<ll> C(m);
    vector<pair<ll, int>> ve;
    for (int i = 0; i < m; i++) {
        cin >> C[i];
        ve.emplace_back(C[i], -i);
    }
    sort(ve.begin(), ve.end());
    int lo = 1, hi = m, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        vector<bool> take(m);
        for (int i = 0; i < mid; i++) {
            take[-ve[i].second] = true;
        }
        bool ok = true;
        ll tmp = 0;
        for (int i = 0; i < m; i++) {
            if (take[i]) {
                if (tmp >= C[i]) {
                    tmp -= C[i];
                } else {
                    ok = false;
                    break;
                }
            }
            tmp += x;
        }
        if (ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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