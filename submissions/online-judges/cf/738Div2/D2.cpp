#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

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

int p1[N + 5], p2[N + 5];
int s1[N + 5], s2[N + 5];

void init () {
    for(int i = 1; i <= N; i++){
        p1[i] = i, s1[i] = 1;
        p2[i] = i, s2[i] = 1;
    }
}

int fpar1(int a) {
    return (a == p1[a] ? a : p1[a] = fpar1(p1[a]));
}

int fpar2(int a) {
    return (a == p2[a] ? a : p2[a] = fpar2(p2[a]));
}

void merge1(int a, int b){
    a = fpar1(a);
    b = fpar1(b);
    if (a != b) {
        if(s1[a] < s1[b]) {
            swap(a,b);
        }
        p1[b] = a;
        s1[a] += s1[b];
    }
}

void merge2(int a, int b){
    a = fpar2(a);
    b = fpar2(b);
    if (a != b) {
        if(s2[a] < s2[b]) {
            swap(a,b);
        }
        p2[b] = a;
        s2[a] += s2[b];
    }
}

int n, m1, m2;

void solve() {
    init();

    cin >> n >> m1 >> m2;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        merge1(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        merge2(u, v);
    }
    vector<pair<int, int>> edges;

    vector<int> v1, v2, P1(n + 1), P2(n + 1);
    map<int, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
        P1[i] = fpar1(i);
        P2[i] = fpar2(i);
        v1.emplace_back(P1[i]), v2.emplace_back(P2[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
    v2.resize(unique(v2.begin(), v2.end()) - v2.begin());
    int tmp = 0;
    for (auto e : v1) { mp1[e] = tmp++; }
    tmp = 0;
    for (auto e : v2) { mp2[e] = tmp++; }
    int sz1 = (int)v1.size(), sz2 = (int)v2.size();

    Dinic flowbip = Dinic(2 + sz1 + sz2, 0, 1 + sz1 + sz2);

    for (int i = 1; i <= sz1; i++) {
        flowbip.add_edge(0, i, 1);
    }

    for (int i = sz1 + 1; i <= sz1 + sz2; i++) {
        flowbip.add_edge(i, sz1 + sz2 + 1, 1);
    }

    for (int i = 1; i <= n; i++) {
        int x1 = mp1[P1[i]];
        int x2 = mp2[P2[i]];
        flowbip.add_edge(x1, x2 + sz1, 1);
    }

    ll ans = flowbip.flow();
    vector<pair<int, int>> E;
    for (auto edge : flowbip.edges) {
        if (edge.flow == 1) {
            E.emplace_back(edge.u, edge.v);
        }
    }
    cerr << ans << ' ' << E.size() << '\n';
    assert(E.size() == ans);
    cout << ans << '\n';
    for (auto t : E) {
        cout << t.first << ' ' << t.second << '\n';
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