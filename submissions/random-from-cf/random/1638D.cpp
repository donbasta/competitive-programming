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
    vector<vector<int>> ar(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    vector<vector<bool>> vis(n - 1, vector<bool>(m - 1));
    int col = m * n;
    queue<vector<int>> Q;
    vector<vector<int>> ret;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int c = ar[i][j];
            if (ar[i + 1][j] == c && ar[i][j + 1] == c && ar[i + 1][j + 1] == c) {
                Q.emplace(vector<int>{i, j, c});
                vis[i][j] = true;
            }
        }
    }
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        ret.push_back(now);
        int ii = now[0], jj = now[1];
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                if (ar[ii + x][jj + y] > 0) ar[ii + x][jj + y] = 0, col--;
            }
        }
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (ii - 1 + x < 0 || jj - 1 + y < 0 || ii + x >= n || jj + y >= m) continue;
                if (vis[ii - 1 + x][jj - 1 + y]) continue;
                set<int> tmp;
                tmp.insert(ar[ii - 1 + x][jj - 1 + y]);
                tmp.insert(ar[ii + x][jj - 1 + y]);
                tmp.insert(ar[ii - 1 + x][jj + y]);
                tmp.insert(ar[ii + x][jj + y]);
                if (tmp.size() == 1) {
                    if (*tmp.begin() == 0) {
                        vis[ii - 1 + x][jj - 1 + y] = true;
                    } else {
                        vis[ii - 1 + x][jj - 1 + y] = true;
                        // ret.emplace_back(vector<int>{ii - 1 + x, jj - 1 + y, *tmp.begin()});
                        Q.emplace(vector<int>{ii - 1 + x, jj - 1 + y, *tmp.begin()});
                    }
                } else if (tmp.size() == 2) {
                    if (*tmp.begin() == 0) {
                        vis[ii - 1 + x][jj - 1 + y] = true;
                        // ret.emplace_back(vector<int>{ii - 1 + x, jj - 1 + y, *tmp.rbegin()});
                        // Q.emplace(ii - 1 + x, jj - 1 + y);
                        Q.emplace(vector<int>{ii - 1 + x, jj - 1 + y, *tmp.rbegin()});
                    }
                }
            }
        }
    }
    if (col > 0) {
        cout << -1 << '\n';
        return;
    }
    reverse(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (auto e : ret) {
        cout << (e[0] + 1) << ' ' << (e[1] + 1) << ' ' << e[2] << '\n';
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