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
const int MOD = 998244353;

void el_psy_congroo() {
    ll m, n, q;
    cin >> n >> m >> q;

    vector<bool> can(8, true);
    int ans = 8;
    cout << ans << '\n';

    vector<vector<vector<int>>> grid = {
        {{0, 0, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}},
        {{1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}},
        {{0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}},
        {{1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}},

        {{0, 1, 0, 1}, {0, 1, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}},
        {{1, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}},
        {{0, 1, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}},
        {{1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}, {1, 0, 1, 0}},
    };

    for (int i = 0; i < q; i++) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        --x, --y;
        x %= 4, y %= 4;
        int col = (s == "circle" ? 0 : 1);
        for (int j = 0; j < 8; j++) {
            if (!can[j]) continue;
            // debug(j, x, y, grid[j][x][y]);
            if (grid[j][x][y] != col) {
                ans--;
                can[j] = false;
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