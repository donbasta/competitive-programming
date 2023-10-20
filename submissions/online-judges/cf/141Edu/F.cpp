#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

struct FlowEdge {
    int v, u, val;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap, int val) : v(v), u(u), cap(cap), val(val) {}
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

    void add_edge(int v, int u, long long cap, int val) {
        edges.emplace_back(v, u, cap, val);
        edges.emplace_back(u, v, 0, val);
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
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
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

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        --b[i];
    }
    int id = 1;
    vector<bool> visa(n), visb(n);
    vector<int> idxa(n, -1), idxb(n, -1);
    for (int i = 0; i < n; i++) {
        if (visa[i]) continue;
        int cur = i;
        visa[cur] = true;
        idxa[cur] = id;
        cur = a[cur];
        while (cur != i) {
            visa[cur] = true;
            idxa[cur] = id;
            cur = a[cur];
        }
        id++;
    }
    int ida = id - 1;
    for (int i = 0; i < n; i++) {
        if (visb[i]) continue;
        int cur = i;
        visb[cur] = true;
        idxb[cur] = id;
        cur = b[cur];
        while (cur != i) {
            visb[cur] = true;
            idxb[cur] = id;
            cur = b[cur];
        }
        id++;
    }
    Dinic D(id + 1, 0, id);
    for (int i = 1; i <= ida; i++) {
        D.add_edge(0, i, 1, -1);
    }
    for (int i = ida + 1; i <= id - 1; i++) {
        D.add_edge(i, id, 1, -1);
    }
    for (int i = 0; i < n; i++) {
        D.add_edge(idxa[i], idxb[i], 1, i);
    }
    int un = D.flow();
    cout << n - un << '\n';
    vector<bool> unu(n);
    for (int i = 0; i < (int)D.edges.size(); i += 2) {
        if (D.edges[i].v == 0 || D.edges[i].u == id) continue;
        if (D.edges[i].flow > 0) {
            unu[D.edges[i].val] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!unu[i]) {
            cout << (i + 1) << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}