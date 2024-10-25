#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<vector<int>> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, vector<int>& T) {
        if (s == e) {
            tree[v] = vector<int>{T[s]};
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
    }
    bool get(int v, int s, int e, int l, int r, int mn, int mx) {
        if (s == l && e == r) {
            int p = lower_bound(tree[v].begin(), tree[v].end(), mn) - tree[v].begin();
            int q = upper_bound(tree[v].begin(), tree[v].end(), mx) - tree[v].begin();
            return (q > p);
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r, mn, mx);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r, mn, mx);
        return get(v << 1, s, mid, l, mid, mn, mx) || get(v << 1 | 1, mid + 1, e, mid + 1, r, mn, mx);
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n), sz(n);
    int T = 0;
    const function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        tin[v] = T++;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            sz[v] += sz[c];
        }
    };
    dfs(0, 0);

    vector<int> p(n), pp(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    // p[i] descendant x --> tin[p[i]] ada di range
    for (int i = 0; i < n; i++) {
        pp[i] = tin[p[i]];
    }

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, pp);

    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r, --x;
        int mn = tin[x];
        int mx = tin[x] + sz[x] - 1;
        bool ok = sgt.get(1, 0, n - 1, l, r, mn, mx);
        cout << (ok ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}