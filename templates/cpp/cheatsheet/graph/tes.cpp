#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

struct EdmondKarp {
    int n, s, t;
    const ll inf = 1e18;
    vector<vector<ll>> cap;
    vector<vector<int>> adj;

    EdmondKarp(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        cap.assign(n, vector<ll>(n));
    }

    void add_edge(int v, int u, ll capacity) {
        cap[v][u] = capacity;
        cap[u][v] = 0;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    ll bfs(vector<int>& par) {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        queue<pair<int, ll>> q;
        q.push({s, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            ll flow = q.front().second;
            q.pop();

            for (int nxt : adj[cur]) {
                if (par[nxt] == -1 && cap[cur][nxt]) {
                    par[nxt] = cur;
                    ll new_flow = min(flow, cap[cur][nxt]);
                    if (nxt == t) {
                        return new_flow;
                    }
                    q.emplace(nxt, new_flow);
                }
            }
        }

        return 0;
    }

    ll maxflow() {
        ll flow = 0;
        vector<int> par(n);
        ll new_flow;

        while (new_flow = bfs(par)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prv = par[cur];
                cap[prv][cur] -= new_flow;
                cap[cur][prv] += new_flow;
                cur = prv;
            }
        }

        return flow;
    }
};

int solveFlow(int n, int prime, vector<pair<int, int>>& edges, vector<map<int, int>>& fac) {
    EdmondKarp E = EdmondKarp(n + 2, 0, n + 1);
    for (int i = 1; i <= n; i += 2) {
        E.add_edge(0, i, fac[i][prime]);
    }
    for (int i = 2; i <= n; i += 2) {
        E.add_edge(i, n + 1, fac[i][prime]);
    }
    for (auto e : edges) {
        int a = e.first, b = e.second;
        if (b & 1) swap(a, b);
        E.add_edge(a, b, INF);
    }
    return E.maxflow();
}

map<int, int> factorize(int x) {
    map<int, int> ret;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int exp = 0;
            while (x % i == 0) {
                exp++, x /= i;
            }
            ret[i] = exp;
        }
    }
    if (x > 1) {
        ret[x] = 1;
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.emplace_back(x, y);
    }
    vector<map<int, int>> fac(n + 1);
    set<int> primes;
    for (int i = 1; i <= n; i++) {
        fac[i] = factorize(ar[i]);
        for (auto e : fac[i]) {
            primes.emplace(e.first);
        }
    }
    int ans = 0;
    for (auto p : primes) {
        ans += solveFlow(n, p, edges, fac);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}