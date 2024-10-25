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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    set<pair<int, pair<int, int>>> Q;
    const int INF = 2e9;
    vector<vector<int>> dis(n + 2, vector<int>(m + 2, INF));
    for (int i = 0; i <= m + 1; i++) {
        Q.emplace(0, make_pair(0, i));
        Q.emplace(0, make_pair(n + 1, i));
        dis[0][i] = dis[n + 1][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        Q.emplace(0, make_pair(i, 0));
        Q.emplace(0, make_pair(i, m + 1));
        dis[i][0] = dis[i][m + 1] = 0;
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    const function<void(int, int, int)> ff = [&](int r, int c, int val) {
        Q.erase(make_pair(dis[r][c], make_pair(r, c)));
        dis[r][c] = val;
        Q.emplace(dis[r][c], make_pair(r, c));
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr <= 0 || nr > n || nc <= 0 || nc > m) continue;
            if (grid[nr][nc] == '1') continue;
            if (dis[nr][nc] == val) continue;
            ff(nr, nc, val);
        }
    };

    while (!Q.empty()) {
        auto now = *Q.begin();
        Q.erase(Q.begin());
        int D = now.first;
        int x = now.second.first, y = now.second.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx >= n + 1 || ny <= 0 || ny >= m + 1) continue;

            if (grid[nx][ny] == '1') {
                if (dis[nx][ny] > dis[x][y] + 1) {
                    Q.erase(make_pair(dis[nx][ny], make_pair(nx, ny)));
                    dis[nx][ny] = dis[x][y] + 1;
                    Q.emplace(dis[nx][ny], make_pair(nx, ny));
                }
            } else {
                if (dis[nx][ny] > dis[x][y]) {
                    ff(nx, ny, dis[x][y]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '0') {
                ans = max(ans, dis[i][j]);
            }
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