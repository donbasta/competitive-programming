#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

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
    const function<int(int, int)> path = [&](int a, int b) -> int {
        return val[a] ^ val[b] ^ ve[lca(a, b)];
    };
    val[0] = ve[0];
    dfs_lca(0, 0);

    vector<int> sz(n), par(n);
    vector<bool> processed(n);
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
    const function<void(int, int)> cd = [&](int v, int p) {
        dfs_size(v, p);
        int cur_sz = sz[v];
        int ctr = get_centroid(v, p, cur_sz);
        par[ctr] = (p == -1 ? ctr : p);
        processed[ctr] = true;
        for (auto c : adj[ctr]) {
            if (processed[c]) continue;
            cd(c, ctr);
        }
        processed[ctr] = false;
    };
    cd(0, -1);

    vector<vector<int>> child_dec(n);
    for (int i = 0; i < n; i++) {
        if (par[i] == i) continue;
        child_dec[par[i]].push_back(i);
    }

    ll ans = 0;
    vector<unordered_map<int, int>> cnt(n);
    const function<void(int, int, int, bool)> dfs_dec = [&](int par, int v, int p, bool isi) {
        int cur_val = path(par, v);
        if (isi) {
            cnt[par][cur_val]++;
        } else {
            if (cnt[par].count(ve[par] ^ cur_val)) {
                ans += cnt[par][ve[par] ^ cur_val];
            }
        }
        for (auto c : child_dec[v]) {
            dfs_dec(par, c, v, isi);
        }
    };

    for (int i = 0; i < n; i++) {
        cnt[i][ve[i]]++;
        for (auto c : child_dec[i]) {
            dfs_dec(i, c, i, false);
            dfs_dec(i, c, i, true);
        }
    }

    cout << ans << '\n';
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