#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
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

    void add_edge(int v, int u, long long cap) {
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
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 1e5;
bool is_prime[N + 5];

void precomp_prime() {
    for (int i = 2; i <= N; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i <= N; i++) {
        if (!is_prime[i]) continue;
        for (int j = i + i; j <= N; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve() {
    precomp_prime();

    int n;
    cin >> n;
    vector<int> ar(n), cnt(2), haha(2 * n + 1);
    vector<vector<pair<int, int>>> ve(2);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i] & 1]++;
        ve[ar[i] & 1].emplace_back(ar[i], i);
        int sz = ve[ar[i] & 1].size();
        haha[sz + (n / 2) * (ar[i] & 1)] = i + 1;
    }
    if (cnt[0] != cnt[1]) {
        cout << "Impossible" << '\n';
        return;
    }
    assert(n % 2 == 0);

    Dinic D = Dinic(n + 2, 0, n + 1);
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (is_prime[ve[0][i].first + ve[1][j].first]) {
                D.add_edge(i + 1, j + 1 + (n / 2), 1);
            }
        }
    }
    for (int i = 1; i <= (n / 2); i++) {
        D.add_edge(0, i, 2);
        D.add_edge(i + (n / 2), n + 1, 2);
    }
    ll mt = D.flow();
    if (mt < n) {
        cout << "Impossible" << '\n';
        return;
    }
    vector<vector<int>> tables;
    vector<vector<int>> adj(n + 1);
    for (auto e : D.edges) {
        if (e.flow > 0 && e.v >= 1 && e.v <= (n / 2)) {
            adj[e.v].push_back(e.u);
            adj[e.u].push_back(e.v);
        }
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n / 2; i++) {
        if (vis[i]) continue;
        int j = i;
        vector<int> table;
        while (!vis[j]) {
            table.emplace_back(haha[j]);
            vis[j] = true;
            if (!vis[adj[j][0]]) {
                j = adj[j][0];
            } else {
                j = adj[j][1];
            }
        }
        tables.emplace_back(table);
    }
    cout << tables.size() << '\n';
    for (auto t : tables) {
        cout << t.size() << ' ';
        for (auto u : t) {
            cout << u << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}