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

const ll INF = 1e15;

void el_psy_congroo() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> s(n);
    for (int i = 0; i < p; i++) {
        cin >> s[i];
        --s[i];
    }
    vector<vector<ll>> D(n, vector<ll>(n, INF));
    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < n; i++) {
        D[i][i] = 0ll;
    }
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        D[u][v] = D[v][u] = w;
    }

    auto dijkstra = [&](int v) {
        set<pair<ll, ll>> se;
        se.emplace(0, v);
        while (!se.empty()) {
            int nw = se.begin()->second;
            se.erase(se.begin());
            for (auto edge : adj[nw]) {
                int to = edge.first;
                int len = edge.second;
                if (max(D[v][nw], 1ll * len) < D[v][to]) {
                    se.erase(make_pair(D[v][to], to));
                    D[v][to] = max(D[v][nw], 1ll * len);
                    se.emplace(D[v][to], to);
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }

    debug(D);

    vector<ll> ans(n + 1);
    vector<bool> use(n);
    vector<int> to(n);
    for (int i = 0; i < p; i++) {
        use[s[i]] = true;
        to[s[i]] = s[i];
    }
    vector<set<pair<ll, ll>>> dist(n);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            dist[s[i]].emplace(make_pair(D[s[i]][s[j]], s[j]));
        }
    }
    ll last_best = 0;
    vector<vector<int>> need(n);
    for (int i = 0; i < p; i++) {
        need[s[i]].push_back(s[i]);
    }

    for (int i = p - 1; i >= 1; i--) {
        ll best = LLONG_MAX;
        int rem = -1;
        for (int j = 0; j < n; j++) {
            if (!use[j]) continue;
            ll tmp = last_best;
            for (auto pp : need[j]) {
                tmp -= D[pp][j];
            }
            for (auto pp : need[j]) {
                dist[pp].erase(make_pair(D[pp][j], j));
                tmp += dist[pp].begin()->first;
                dist[pp].emplace(D[pp][j], j);
            }
            if (tmp <= best) {
                best = tmp;
                rem = j;
            }
        }
        use[rem] = false;
        for (auto pp : need[rem]) {
            dist[pp].erase(make_pair(D[pp][rem], rem));
            auto nw = *dist[pp].begin();
            need[nw.second].push_back(pp);
        }
        for (int i = 0; i < p; i++) {
            dist[s[i]].erase(make_pair(D[s[i]][rem], rem));
        }
        last_best = best;
        ans[i] = best;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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