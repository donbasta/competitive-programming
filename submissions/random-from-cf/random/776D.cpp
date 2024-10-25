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
    vector<int> R(n), tmp(n, -1);
    vector<vector<pair<int, int>>> adj(m);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            --y;
            if (tmp[y] == -1) {
                tmp[y] = i;
            } else {
                adj[tmp[y]].emplace_back(i, R[y] ^ 1);
                adj[i].emplace_back(tmp[y], R[y] ^ 1);
            }
        }
    }
    // debug(adj);
    vector<int> col(m, -1);

    const function<bool(int)> dfs = [&](int root) -> bool {
        bool ret = true;
        for (auto c : adj[root]) {
            if (col[c.first] != -1) {
                if (col[c.first] ^ c.second != col[root]) ret = false;
            } else {
                col[c.first] = col[root] ^ c.second;
                ret &= dfs(c.first);
            }
        }
        return ret;
    };

    for (int i = 0; i < m; i++) {
        if (col[i] != -1) continue;
        col[i] = 0;
        if (!dfs(i)) {
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
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}