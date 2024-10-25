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
    int ar[3][n];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
            if (ar[i][j] < 0) {
                ar[i][j] = 2 * (-ar[i][j] - 1) + 1;
            } else {
                ar[i][j] = 2 * (ar[i][j] - 1);
            }
            assert(ar[i][j] >= 0 && ar[i][j] < 2 * n);
        }
    }
    vector<vector<int>> adj(2 * n), adj_t(2 * n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            int kk = (k + 1) % 3;
            int p = ar[k][i];
            int q = ar[kk][i];

            adj[p ^ 1].push_back(q);
            adj[q ^ 1].push_back(p);
            adj_t[q].push_back(p ^ 1);
            adj_t[p].push_back(q ^ 1);
        }
    }

    vector<bool> used(2 * n);
    vector<int> order, comp(2 * n, -1);
    function<void(int)> dfs1 = [&](int v) {
        used[v] = true;
        for (auto c : adj[v]) {
            if (!used[c]) dfs1(c);
        }
        order.push_back(v);
    };
    function<void(int, int)> dfs2 = [&](int v, int c1) {
        comp[v] = c1;
        for (auto c : adj_t[v]) {
            if (comp[c] == -1) dfs2(c, c1);
        }
    };

    for (int i = 0; i < 2 * n; i++)
        if (!used[i]) dfs1(i);
    for (int i = 0, j = 0; i < 2 * n; i++) {
        int v = order[2 * n - i - 1];
        if (comp[v] == -1) dfs2(v, j++);
    }
    for (int i = 0; i < 2 * n; i += 2) {
        if (comp[i] == comp[i + 1]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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