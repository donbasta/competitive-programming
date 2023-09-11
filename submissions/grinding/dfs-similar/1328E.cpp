#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct LCA {
    vector<int> tin, tout, par, depth;
    int timer, len;
    vector<vector<int>> up, adj;

    LCA(int n, vector<vector<int>>& adj) : adj(adj) {
        tin.resize(n);
        tout.resize(n);
        par.resize(n);
        depth.resize(n);
        timer = 0;
        len = ceil(log2(n));
        up.assign(n, vector<int>(len + 1));
        dfs(0, 0);
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= len; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            depth[c] = depth[v] + 1;
            dfs(c, v);
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = len; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA tree(n, adj);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> tmp;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            --x;
            tmp.push_back(tree.par[x]);
        }
        sort(tmp.begin(), tmp.end(), [&](int a, int b) -> bool {
            return tree.depth[a] > tree.depth[b];
        });
        bool ok = true;
        for (int i = 1; i < k; i++) {
            if (!tree.is_ancestor(tmp[i], tmp[i - 1])) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
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