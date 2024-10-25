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
    int h, w, y;
    cin >> h >> w >> y;
    int grid[h][w], dead[h][w];
    bool in[h][w];
    memset(in, false, sizeof(in));
    memset(dead, -1, sizeof(dead));
    const int M = 1e5;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    set<pair<int, pair<int, int>>> se;
    for (int i = 0; i < h; i++) {
        se.emplace(grid[i][0], make_pair(i, 0));
        se.emplace(grid[i][w - 1], make_pair(i, w - 1));
        in[i][0] = in[i][w - 1] = true;
    }
    for (int i = 1; i < w - 1; i++) {
        se.emplace(grid[0][i], make_pair(0, i));
        se.emplace(grid[h - 1][i], make_pair(h - 1, i));
        in[0][i] = in[h - 1][i] = true;
    }

    for (int i = 1; i <= M; i++) {
        while (!se.empty() && se.begin()->first <= i) {
            auto cur = *se.begin();
            se.erase(se.begin());
            // debug(cur);
            int ch = cur.second.first, cw = cur.second.second;
            dead[ch][cw] = i;
            for (int k = 0; k < 4; k++) {
                int nh = ch + dx[k], nw = cw + dy[k];
                if (nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
                // if (dead[nh][nw] != -1) continue;
                if (in[nh][nw]) continue;
                // if (grid[nh][nw] <= i) {
                //     dead[nw][nw] = i;
                // }
                se.emplace(grid[nh][nw], make_pair(nh, nw));
                in[nh][nw] = true;
            }
        }
    }

    vector<int> ans(M + 1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans[1]++;
            ans[dead[i][j]]--;
        }
    }
    for (int i = 2; i <= M; i++) ans[i] += ans[i - 1];
    for (int i = 1; i <= y; i++) {
        cout << ans[i] << '\n';
    }
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