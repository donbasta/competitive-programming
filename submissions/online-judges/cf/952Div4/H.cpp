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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> id(n, vector<int>(m, -1));
    vector<int> ar(m * n);

    int cc = 0, cs = 0;

    function<void(int, int, int)> ff = [&](int r, int c, int x) {
        cs++;
        id[r][c] = x;
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '.') continue;
            if (vis[nr][nc]) continue;
            vis[nr][nc] = true;
            ff(nr, nc, x);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            if (vis[i][j]) continue;
            cs = 0;
            vis[i][j] = true;
            ff(i, j, cc);
            ar[cc++] = cs;
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        set<int> ids;
        int cur_area = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.')
                cur_area++;
            else {
                if (ids.count(id[i][j]))
                    continue;
                else {
                    ids.insert(id[i][j]);
                    cur_area += ar[id[i][j]];
                }
            }
            if (i > 0) {
                if (grid[i - 1][j] == '#') {
                    if (!ids.count(id[i - 1][j])) {
                        ids.insert(id[i - 1][j]);
                        cur_area += ar[id[i - 1][j]];
                    }
                }
            }
            if (i < n - 1) {
                if (grid[i + 1][j] == '#') {
                    if (!ids.count(id[i + 1][j])) {
                        ids.insert(id[i + 1][j]);
                        cur_area += ar[id[i + 1][j]];
                    }
                }
            }
        }
        mx = max(mx, cur_area);
    }
    for (int i = 0; i < m; i++) {
        set<int> ids;
        int cur_area = 0;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == '.')
                cur_area++;
            else {
                if (ids.count(id[j][i]))
                    continue;
                else {
                    ids.insert(id[j][i]);
                    cur_area += ar[id[j][i]];
                }
            }
            if (i > 0) {
                if (grid[j][i - 1] == '#') {
                    if (!ids.count(id[j][i - 1])) {
                        ids.insert(id[j][i - 1]);
                        cur_area += ar[id[j][i - 1]];
                    }
                }
            }
            if (i < m - 1) {
                if (grid[j][i + 1] == '#') {
                    if (!ids.count(id[j][i + 1])) {
                        ids.insert(id[j][i + 1]);
                        cur_area += ar[id[j][i + 1]];
                    }
                }
            }
        }

        mx = max(mx, cur_area);
    }

    cout << mx << '\n';
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