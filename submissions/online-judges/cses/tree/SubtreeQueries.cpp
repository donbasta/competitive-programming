#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<ll> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<ll>& ar) {
        if (s == e) {
            tree[v] = ar[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, ar);
            build(v << 1 | 1, mid + 1, e, ar);
            tree[v] = tree[v << 1] + tree[v << 1 | 1];
        }
    }
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) {
            upd(v << 1, s, mid, idx, val);
        } else {
            upd(v << 1 | 1, mid + 1, e, idx, val);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return get(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return get(v << 1 | 1, mid + 1, e, l, r);
        }
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n);
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
    int timer = 0;
    vector<int> tin(n, -1), tout(n, -1);
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        tin[v] = timer++;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
        }
        tout[v] = timer++;
    };
    dfs(0, 0);
    assert(timer == 2 * n);
    vector<ll> dfs_array(2 * n);
    for (int i = 0; i < n; i++) {
        dfs_array[tin[i]] = dfs_array[tout[i]] = val[i];
    }
    Segtree sgt(2 * n);
    sgt.build(1, 0, 2 * n - 1, dfs_array);
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int s, x;
            cin >> s >> x;
            --s;
            sgt.upd(1, 0, 2 * n - 1, tin[s], x);
            sgt.upd(1, 0, 2 * n - 1, tout[s], x);
        } else if (tp == 2) {
            int s;
            cin >> s;
            --s;
            ll sum = sgt.get(1, 0, 2 * n - 1, tin[s], tout[s]);
            sum /= 2;
            cout << sum << '\n';
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