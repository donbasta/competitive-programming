#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int timer = 0;
    vector<int> tin(n), tout(n), dis(n);
    const int B = 20;
    vector<vector<int>> up(n, vector<int>(B + 1));
    const function<void(int, int)> dfs_lca = [&](int v, int p) {
        tin[v] = timer++;
        up[v][0] = p;
        for (int i = 1; i <= B; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            dis[c] = dis[v] + 1;
            dfs_lca(c, v);
        }
        tout[v] = timer++;
    };
    const function<bool(int, int)> is_ancestor = [&](int a, int b) -> bool {
        return (tin[a] <= tin[b] && tout[a] >= tout[b]);
    };
    const function<int(int, int)> lca = [&](int u, int v) -> int {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = B; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    };
    const function<int(int, int)> D = [&](int a, int b) -> int {
        return dis[a] + dis[b] - 2 * dis[lca(a, b)];
    };

    vector<bool> processed(n);
    vector<int> sz(n), par(n);
    const function<void(int, int)> dfs_size = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p || processed[c]) continue;
            dfs_size(c, v);
            sz[v] += sz[c];
        }
    };
    const function<int(int, int, int)> get_centroid = [&](int v, int p, int comp_size) -> int {
        for (auto c : adj[v]) {
            if (c == p || processed[c]) continue;
            if (sz[c] > (comp_size / 2)) return get_centroid(c, v, comp_size);
        }
        return v;
    };
    const function<void(int, int)> centroid_decomposition = [&](int v, int p) {
        dfs_size(v, p);
        int cur_sz = sz[v];
        int ctr = get_centroid(v, p, cur_sz);
        par[ctr] = (p == -1 ? ctr : p);
        processed[ctr] = true;
        for (auto c : adj[ctr]) {
            if (processed[c]) continue;
            centroid_decomposition(c, ctr);
        }
        processed[ctr] = false;
    };

    dfs_lca(0, 0);
    centroid_decomposition(0, -1);
    vector<multiset<int>> ans(n);
    vector<int> col(n);

    const function<void(int)> upd = [&](int u) {
        int tu = u;
        while (true) {
            if (!col[u]) {
                ans[tu].insert(D(tu, u));
            } else {
                ans[tu].erase(ans[tu].find(D(tu, u)));
            }
            if (tu == par[tu]) break;
            tu = par[tu];
        }
        col[u] ^= 1;
    };

    const function<int(int)> que = [&](int u) {
        int tu = u;
        int ret = INF;
        while (true) {
            if (!ans[tu].empty()) {
                ret = min(ret, D(tu, u) + *ans[tu].begin());
            }
            if (tu == par[tu]) break;
            tu = par[tu];
        }
        return (ret == INF ? -1 : ret);
    };

    int m;
    cin >> m;
    while (m--) {
        int t, v;
        cin >> t >> v;
        --v;
        if (t == 0) {
            upd(v);
        } else {
            cout << que(v) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}