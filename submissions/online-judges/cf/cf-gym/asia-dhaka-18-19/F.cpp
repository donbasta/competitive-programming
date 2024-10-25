#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

// set all elements in range l, r to 0 or 1
// get sum of elements in range l, r
struct Segtree {
    int n;
    vector<int> tree, lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5, -1), n(n) {}
    void push(int v, int s, int e) {
        if (lz[v] == -1) return;
        if (lz[v] == 0) {
            tree[v << 1] = tree[v << 1 | 1] = 0;
            lz[v << 1] = lz[v << 1 | 1] = 0;
        } else if (lz[v] == 1) {
            int mid = (s + e) >> 1;
            tree[v << 1] = (mid - s + 1);
            tree[v << 1 | 1] = (e - mid);
            lz[v << 1] = lz[v << 1 | 1] = 1;
        }
        lz[v] = -1;
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            lz[v] = val;
            if (val == 0)
                tree[v] = 0;
            else if (val == 1)
                tree[v] = (e - s + 1);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        push(v, s, e);
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    void upd(int l, int r, int val) {
        if (l > r) return;
        upd(1, 0, n - 1, l, r, val);
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(1, 0, n - 1, l, r);
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

    Segtree sgt(n);
    int T = 0;
    vector<int> sz(n), par(n), dep(n), id(n), tp(n);
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
    dfs_sz(0, 0);
    dfs_hld(0, 0, 0);

    const function<void(int, int)> path = [&](int x, int y) {
        vector<pair<int, int>> itv;
        while (tp[x] != tp[y]) {
            if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
            itv.emplace_back(id[tp[x]], id[x]);
            x = par[tp[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        itv.emplace_back(id[x], id[y]);
        sort(itv.begin(), itv.end());
        int l = 0;
        for (int i = 0; i < itv.size(); i++) {
            // cerr << l << ' ' << itv[i].first - 1 << '\n';
            sgt.upd(l, itv[i].first - 1, 0);
            l = itv[i].second + 1;
        }
        // cerr << l << ' ' << n - 1 << '\n';
        sgt.upd(l, n - 1, 0);
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        sgt.upd(0, n - 1, 1);
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            path(a, b);
        }
        cout << sgt.get(0, n - 1) << '\n';
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