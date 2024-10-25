#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<int> tree, lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    void push(int v, int s, int e) {
        if (lz[v] == 0) return;
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
        tree[v << 1] += lz[v];
        tree[v << 1 | 1] += lz[v];
        lz[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            lz[v] += val;
            tree[v] += val;
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
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(
            get(v << 1, s, mid, l, mid),
            get(v << 1 | 1, mid + 1, e, mid + 1, r));
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

    int T = 0;
    vector<int> tin(n), sz(n), dep(n), dep_eul(n * 2), tout(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        tin[v] = T++;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dep[c] = dep[v] + 1;
            dfs(c, v);
        }
        tout[v] = T++;
    };
    dfs(0, 0);
    Segtree sgt(n * 2);
    for (int i = 0; i < n; i++) {
        dep_eul[tin[i]] = dep_eul[tout[i]] = dep[i];
    }
    sgt.build(1, 0, n * 2 - 1, dep_eul);

    vector<int> X(q), ret(q);
    vector<vector<int>> K(q);
    for (int i = 0; i < q; i++) {
        int k;
        cin >> X[i] >> k;
        --X[i];
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            --a;
            K[i].push_back(a);
        }
    }
    vector<int> ord(q);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) -> bool {
        return tin[x] < tin[y];
    });
    int cur = 0;
    for (int i = 0; i < q; i++) {
    }

    for (int i = 0; i < q; i++) {
        cout << ret[i] << '\n';
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