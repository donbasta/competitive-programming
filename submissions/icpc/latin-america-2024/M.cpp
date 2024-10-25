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

const ll INF = 2e18;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    int p, g;
    cin >> p >> g;
    --p, --g;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        ll u, v, d;
        cin >> u >> v >> d;
        --u, --v;
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }

    vector<vector<int>> par(n);
    auto dijkstra = [&](int v) -> vector<ll> {
        vector<ll> ret(n, INF);
        set<pair<ll, int>> se;
        ret[v] = 0;
        se.emplace(0, v);
        while (!se.empty()) {
            auto now = *se.begin();
            int cur = now.second;
            ll dis = now.first;
            se.erase(se.begin());
            for (auto c : adj[cur]) {
                if (c.second + dis < ret[c.first]) {
                    par[c.first].clear();
                    se.erase(make_pair(ret[c.first], c.first));
                    ret[c.first] = c.second + dis;
                    se.emplace(ret[c.first], c.first);
                    par[c.first].push_back(cur);
                } else if (c.second + dis == ret[c.first]) {
                    par[c.first].push_back(cur);
                }
            }
        }
        return ret;
    };

    vector<ll> G = dijkstra(g);
    vector<ll> P = dijkstra(p);
    vector<bool> cand(n), ok(n);
    for (int i = 0; i < n; i++) {
        if (P[g] * 2 == P[i] && G[i] == P[g]) {
            cand[i] = true;
        }
    }
    debug(P, G, cand);

    vector<vector<int>> to(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        in[i] = par[i].size();
        for (auto c : par[i]) {
            to[c].push_back(i);
        }
    }
    vector<bool> visit_g(n, true);
    queue<int> Q;
    Q.emplace(p);
    visit_g[p] = false;
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        if (now == g) {
            visit_g[g] = true;
        }
        for (auto c : to[now]) {
            visit_g[c] = (visit_g[c] && visit_g[now]);
            --in[c];
            if (in[c] == 0) {
                Q.emplace(c);
            }
        }
    }
    debug(par, visit_g);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (cand[i] && visit_g[i]) ans.push_back(i);
    }
    if (ans.empty()) {
        cout << "*" << '\n';
        return;
    }
    for (auto e : ans) {
        cout << (e + 1) << ' ';
    }
    cout << '\n';
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