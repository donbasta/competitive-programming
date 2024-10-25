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
    vector<vector<int>> edges;
    set<int> col_unique;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        col_unique.insert(c);
        edges.emplace_back(vector<int>{u, v, c});
    }
    int col_sz = col_unique.size(), ptr = 0;
    map<int, int> mp;
    for (auto col : col_unique) {
        mp[col] = ptr++;
    }
    vector<set<int>> cc(col_sz);
    vector<vector<pair<int, int>>> adj(n + col_sz);
    for (auto e : edges) {
        cc[mp[e[2]]].insert(e[0]);
        cc[mp[e[2]]].insert(e[1]);
    }
    for (int i = 0; i < col_sz; i++) {
        for (auto e : cc[i]) {
            adj[e].emplace_back(n + i, 1);
            adj[n + i].emplace_back(e, 0);
        }
    }

    int B, E;
    cin >> B >> E;
    --B, --E;

    vector<int> dis(n + col_sz, INF);
    dis[B] = 0;
    set<pair<int, int>> se;
    se.emplace(dis[B], B);
    while (!se.empty()) {
        auto dv = *se.begin();
        int d = dv.first, v = dv.second;
        se.erase(se.begin());
        for (auto nxdd : adj[v]) {
            int nx = nxdd.first, dd = nxdd.second;
            if (dd + d < dis[nx]) {
                se.erase(make_pair(dis[nx], nx));
                dis[nx] = dd + d;
                se.emplace(dis[nx], nx);
            }
        }
    }
    cout << dis[E] << '\n';
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