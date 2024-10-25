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
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    int q;
    cin >> q;

    auto sq_root = [&](ll a) -> ll {
        ll L = 1, R = 3ll * 1e9, ret = -1;
        while (L <= R) {
            ll mid = (L + R) >> 1;
            if (mid * mid > a) {
                R = mid - 1;
            } else {
                ret = mid;
                L = mid + 1;
            }
        }
        return ret;
    };

    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll det = x * x - y * 4;
        if (det < 0) {
            cout << 0 << ' ';
        } else if (det == 0) {
            ll byk = cnt[x / 2];
            cout << (byk * (byk - 1) / 2) << ' ';
        } else {
            ll sq = sq_root(det);
            if (sq * sq != det) {
                cout << 0 << ' ';
            } else {
                ll a = cnt[(x - sq) / 2];
                ll b = cnt[(x + sq) / 2];
                cout << (a * b) << ' ';
            }
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