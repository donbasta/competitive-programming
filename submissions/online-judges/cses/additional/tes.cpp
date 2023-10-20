#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct FlowEdge {
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap = 1) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1) {
                    continue;
                }
                if (level[edges[id].u] != -1) {
                    continue;
                }
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if (pushed == 0) {
            return 0;
        }
        if (v == t) {
            return pushed;
        }
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) {
                continue;
            }
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) {
                continue;
            }
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (1) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) {
                break;
            }
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 100;
const ll INF = 1e18;

int n, m;
ll sum = 0, sum_b = 0;
int ans[N + 5][N + 5];

void solve() {
    cin >> n >> m;
    Dinic mf = Dinic(2 * n + 2, 0, 2 * n + 1);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        mf.add_edge(0, i, x);
        mf.add_edge(i, n + i, INF);
        sum += x;
    }
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        mf.add_edge(n + i, 2 * n + 1, x);
        sum_b += x;
    }
    int x, y;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        mf.add_edge(x, y + n, INF);
        mf.add_edge(y, x + n, INF);
    }
    ll maxflow = mf.flow();

    if (sum != sum_b || maxflow != sum) {
        cout << "NO" << '\n';
        return;
    }
    for (auto edge : mf.edges) {
        if (edge.v == 0 || edge.v == 2 * n + 1) {
            continue;
        }
        if (edge.u == 0 || edge.u == 2 * n + 1) {
            continue;
        }
        if (edge.v > n) {
            continue;
        }
        ans[edge.v][edge.u - n] = edge.flow;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
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