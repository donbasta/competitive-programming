int timer = 0;
vector<int> tin(n), tout(n), val(n);
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
        val[c] = val[v] ^ ve[c];
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
const function<int(int, int)> dis = [&](int a, int b) -> int {
    return val[a] ^ val[b] ^ ve[lca(a, b)];
};
val[0] = ve[0];
dfs_lca(0, 0);

vector<int> sz(n), par(n);
vector<bool> processed(n);
const function<void(int, int)> dfs_size = [&](int v, int p) {
    sz[v] = 1;
    for (auto c : adj[v]) {
        if (c.first == p || processed[c.first]) continue;
        dfs_size(c.first, v);
        sz[v] += sz[c.first];
    }
};
const function<int(int, int, int)> get_centroid = [&](int v, int p, int comp_size) -> int {
    for (auto c : adj[v]) {
        if (c.first == p || processed[c.first]) continue;
        if (sz[c.first] > (comp_size / 2)) return get_centroid(c.first, v, comp_size);
    }
    return v;
};
const function<void(int, int)> cd = [&](int v, int p) {
    dfs_size(v, p);
    int cur_sz = sz[v];
    int ctr = get_centroid(v, p, cur_sz);
    par[ctr] = (p == -1 ? ctr : p);
    processed[ctr] = true;
    for (auto c : adj[ctr]) {
        if (processed[c.first]) continue;
        cd(c.first, ctr);
    }
    processed[ctr] = false;
};
cd(0, -1);