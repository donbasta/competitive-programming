struct EdmondKarp {
    int n, s, t;
    const ll INF = 1e18;
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
        q.emplace(s, INF);
        while (!q.empty()) {
            int cur = q.front().first;
            ll flow = q.front().second;
            for (auto c : adj[cur]) {
                if (par[c] == -1 && cap[cur][c]) {
                    par[c] = cur;
                    ll new_flow = min(flow, cap[cur][c]);
                    if (c == t) return new_flow;
                    q.emplace(c, new_flow);
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
}