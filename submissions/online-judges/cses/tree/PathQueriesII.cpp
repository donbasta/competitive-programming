#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : tree(4 * n + 5), n(n) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int idx, int val) {
        upd(1, 0, n - 1, idx, val);
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n), sz(n), par(n), dep(n);
    vector<int> st(4 * n + 5), id(n), tp(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

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
        sgt.upd(id[v], val[v]);
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

    const function<int(int, int)> path = [&](int x, int y) -> int {
        int ret = 0;
        while (tp[x] != tp[y]) {
            if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
            ret = max(ret, sgt.get(id[tp[x]], id[x]));
            x = par[tp[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        ret = max(ret, sgt.get(id[x], id[y]));
        return ret;
    };

    dfs_sz(0, 0);
    dfs_hld(0, 0, 0);

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            --x;
            val[x] = y;
            sgt.upd(id[x], val[x]);
        } else if (t == 2) {
            --x, --y;
            int res = path(x, y);
            cout << res << '\n';
        }
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