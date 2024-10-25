#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 20;

struct SparseTable {
    vector<vector<int>> table;
    int n;
    SparseTable() {}
    SparseTable(const vector<int>& ar) : n(ar.size()) {
        table.resize(B + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= B; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return min(table[i][l], table[i][r - (1 << i) + 1]);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int T = 0;
    vector<int> tin(n), tout(n), dep(n);
    vector<vector<int>> up(n, vector<int>(B + 1));
    const function<void(int, int)> dfs_lca = [&](int v, int p) {
        tin[v] = T++;
        up[v][0] = p;
        for (int i = 1; i <= B; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            dep[c] = dep[v] + 1;
            dfs_lca(c, v);
        }
        tout[v] = T++;
    };
    auto is_ancestor = [&](int a, int b) -> bool {
        return (tin[a] <= tin[b] && tout[a] >= tout[b]);
    };
    auto lca = [&](int u, int v) -> int {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = B; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    };
    auto dis = [&](int a, int b) -> int {
        return dep[a] + dep[b] - 2 * dep[lca(a, b)];
    };
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
    };
    cd(0, -1);

    vector<vector<int>> child_dec(n);
    for (int i = 0; i < n; i++) {
        if (par[i] == i) continue;
        child_dec[par[i]].push_back(i);
    }

    vector<vector<pair<int, int>>> chd(n);
    const function<void(int, int)> dfs_cen = [&](int par, int v) {
        chd[par].emplace_back(v, dis(par, v));
        for (auto c : child_dec[v]) {
            dfs_cen(par, c);
        }
    };

    vector<SparseTable> st(n);
    for (int i = 0; i < n; i++) {
        dfs_cen(i, i);
        sort(chd[i].begin(), chd[i].end());
        vector<int> tmp;
        for (auto e : chd[i]) {
            tmp.push_back(e.second);
        }
        st[i] = SparseTable(tmp);
    }

    auto que = [&](int idx, int l, int r) -> int {
        return st[idx].get(l, r);
    };

    int q;
    cin >> q;
    unordered_map<int, pair<int, int>> ump;
    for (int i = 0; i < q; i++) {
        int e;
        cin >> e;
        if (e == 1) {
            int x, l, r;
            cin >> x >> l >> r;
            --l, --r;
            ump[x] = make_pair(l, r);
        } else if (e == 2) {
            int x;
            cin >> x;
            ump.erase(x);
        } else if (e == 3) {
            int c, m;
            cin >> c >> m;
            --c;
            vector<pair<int, int>> itv;
            for (int j = 0; j < m; j++) {
                int p;
                cin >> p;
                if (ump.count(p)) {
                    itv.emplace_back(ump[p]);
                }
            }
            int cen = c;
            int ans = INT_MAX;
            while (true) {
                int tmp = dis(c, cen);
                int mn = INT_MAX;
                for (auto e : itv) {
                    int l = lower_bound(chd[cen].begin(), chd[cen].end(), make_pair(e.first, -1)) - chd[cen].begin();
                    int r = upper_bound(chd[cen].begin(), chd[cen].end(), make_pair(e.second + 1, -1)) - chd[cen].begin();
                    --r;
                    if (l > r) continue;
                    mn = min(mn, que(cen, l, r));
                }
                if (mn != INT_MAX) {
                    ans = min(ans, tmp + mn);
                }
                if (par[cen] == cen) break;
                cen = par[cen];
            }
            if (ans == INT_MAX) ans = -1;
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case " << i << ":\n";
        el_psy_congroo();
    }

    return 0;
}