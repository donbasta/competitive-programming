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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](int start) -> vector<pair<int, int>> {
        vector<pair<int, int>> V(n);
        const function<void(int, int, int)> rec = [&](int v, int p, int dis) {
            V[v].first = dis, V[v].second = p;
            for (auto c : adj[v]) {
                if (c == p) continue;
                rec(c, v, dis + 1);
            }
        };
        rec(start, -1, 0);
        return V;
    };

    vector<pair<int, int>> dis = dfs(0);
    int mx = -1, loc = -1, loc2 = -1;
    for (int i = 0; i < n; i++) {
        if (dis[i].first > mx) {
            mx = dis[i].first, loc = i;
        }
    }
    mx = -1;
    dis = dfs(loc);
    for (int i = 0; i < n; i++) {
        if (dis[i].first > mx) {
            mx = dis[i].first, loc2 = i;
        }
    }
    vector<bool> in_path(n), col(n);
    int cur = loc2;
    vector<int> path;
    while (cur != loc) {
        in_path[cur] = true;
        path.push_back(cur);
        cur = dis[cur].second;
    }
    in_path[cur] = true;
    path.push_back(cur);
    int sz = path.size();
    for (int i = (sz + 1) / 2; i < sz; i++) {
        col[path[i]] = 1;
    }
    int cur_col = ((sz % 2 == 0) ? 0 : 1);
    for (int i = 0; i < n; i++) {
        if (in_path[i]) continue;
        col[i] = cur_col;
        cur_col ^= 1;
    }
    for (int i = 0; i < n; i++) {
        cout << (col[i] ? 'R' : 'B');
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