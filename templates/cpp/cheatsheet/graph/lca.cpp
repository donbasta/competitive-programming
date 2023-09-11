struct LCA {
    vector<int> tin, tout;
    int timer, len;
    vector<vector<int>> up, adj;

    LCA(n, vector<vector<int>>& adj) : adj(adj) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        len = ceil(log2(n));
        up.assign(n, vector<int>(len + 1));
        dfs(0, 0);
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= len; i++) {
            up[v][i] = up[up[v[i - 1]]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
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

    int get_kth_ancestor(int u, int k) {
        if (depth[u] < k) return -1;  // depth of u is less than k, no kth ancestor
        int cur = 0;
        int ret = u;
        for (int i = len; i >= 0; i--) {
            if (cur + (1 << i) > k) continue;
            cur += (1 << i);
            ret = up[ret][i];
        }
        return ret;
    }
}