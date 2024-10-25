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
    int a, b;
    cin >> a >> b;

    int ans = 0;
    vector<int> func(6);

    int t2 = 0, t0 = 0, t11 = 0, t12 = 0;

    const function<void(int)> rec = [&](int idx) {
        if (idx == 6) {
            bool ok = true;
            for (int i = 1; i <= 5; i++) {
                int cek = func[func[i]];
                if (cek != a && cek != b) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
            if (ok) {
                if (func[a] == b && func[b] == a) {
                    t2++;
                } else if (func[a] == a && func[b] == b) {
                    t0++;
                } else if (func[a] == a) {
                    // debug(func);
                    t11++;
                } else if (func[b] == b) {
                    debug(func);
                    t12++;
                }
                // debug(func);
            }
        } else {
            for (int i = 1; i <= 5; i++) {
                func[idx] = i;
                rec(idx + 1);
            }
        }
    };
    rec(1);
    cerr << t0 << ' ' << t11 << ' ' << t12 << ' ' << t2 << '\n';
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