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
const int K = 7;

void el_psy_congroo() {
    vector<string> grid(K);
    for (int i = 0; i < K; i++) cin >> grid[i];
    vector<pair<int, int>> bl, wh;
    for (int i = 1; i < K - 1; i++) {
        for (int j = 1; j < K - 1; j++) {
            if (grid[i][j] != 'B') continue;
            if ((i + j) & 1)
                bl.emplace_back(i, j);
            else
                wh.emplace_back(i, j);
        }
    }

    const function<bool(int, int, vector<string> &)> bad = [&](int r, int c, vector<string> &tmp) -> bool {
        int ret = 0;
        ret += tmp[r][c] == 'B';
        ret += tmp[r + 1][c + 1] == 'B';
        ret += tmp[r + 1][c - 1] == 'B';
        ret += tmp[r - 1][c + 1] == 'B';
        ret += tmp[r - 1][c - 1] == 'B';
        return ret == 5;
    };

    const function<int(vector<pair<int, int>> &, int)> calc = [&](vector<pair<int, int>> &T, int rem) -> int {
        int sz = T.size(), ans = INF;
        if (sz == 0) return 0;
        for (int i = 0; i < (1 << sz); i++) {
            vector<string> tmp = grid;
            for (int j = 0; j < sz; j++) {
                if (!((i >> j) & 1)) continue;
                assert(tmp[T[j].first][T[j].second] == 'B');
                tmp[T[j].first][T[j].second] = 'W';
            }
            bool ok = true;
            for (int r = 1; r < K - 1; r++) {
                for (int c = 1; c < K - 1; c++) {
                    if (tmp[r][c] == 'W') continue;
                    if ((r + c) % 2 != rem) continue;
                    if (bad(r, c, tmp)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                ans = min(ans, __builtin_popcount(i));
            }
        }
        return ans;
    };

    int ret = calc(bl, 1) + calc(wh, 0);
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