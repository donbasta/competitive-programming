#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
    vector<int> res;
    int i = 0, j = 0;
    while ((res.size() < 10) && (i < v1.size() || j < v2.size())) {
        if (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                res.push_back(v1[i++]);
            } else {
                res.push_back(v2[j++]);
            }
        } else if (i < v1.size()) {
            res.push_back(v1[i++]);
        } else {
            res.push_back(v2[j++]);
        }
    }
    return res;
}

struct Segtree {
    int n;
    vector<vector<int>> tree;
    Segtree(int n) : tree(4 * n + 5), n(n) {}
    void build(int v, int s, int e, const vector<vector<int>>& T) {
        if (s == e) {
            tree[v] = T[s];
            if (tree[v].size() > 10) tree[v].resize(10);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
    vector<int> get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return merge(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    vector<int> get(int l, int r) {
        if (l > r) return vector<int>{};
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> pop(n), pop_nw(n);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        --c;
        pop[c].push_back(i);
    }

    vector<int> sz(n), par(n), dep(n), id(n), tp(n);

    Segtree sgt(n);
    int T = 0;
    const function<void(int, int)> dfs_sz = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            dep[c] = dep[v] + 1;
            dfs_sz(c, v);
            sz[v] += sz[c];
        }
    };
    const function<void(int, int, int)> dfs_hld = [&](int v, int p, int top) {
        id[v] = T++;
        tp[v] = top;
        pop_nw[id[v]] = pop[v];
        int mx_c = -1, mx_sz = -1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (sz[c] > mx_sz) {
                mx_sz = sz[c];
                mx_c = c;
            }
        }
        if (mx_c == -1) return;
        dfs_hld(mx_c, v, top);
        for (auto c : adj[v]) {
            if (c == p || c == mx_c) continue;
            dfs_hld(c, v, c);
        }
    };

    const function<vector<int>(int, int)> path = [&](int x, int y) -> vector<int> {
        vector<int> ret;
        while (tp[x] != tp[y]) {
            if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
            ret = merge(ret, sgt.get(id[tp[x]], id[x]));
            x = par[tp[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        ret = merge(ret, sgt.get(id[x], id[y]));
        return ret;
    };

    dfs_sz(0, 0);
    dfs_hld(0, 0, 0);
    sgt.build(1, 0, n - 1, pop_nw);

    for (int i = 0; i < q; i++) {
        int v, u, a;
        cin >> v >> u >> a;
        --v, --u;
        vector<int> T = path(v, u);
        if (T.size() > a) T.resize(a);
        cout << T.size() << ' ';
        for (auto c : T) {
            cout << (c + 1) << ' ';
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
        el_psy_congroo();
    }

    return 0;
}