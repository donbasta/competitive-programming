#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<ll> tree, lz;
    vector<bool> all_zero;
    Segtree(int n) {
        tree.resize(4 * n + 5);
        lz.resize(4 * n + 5);
        all_zero.resize(4 * n + 5);
    }
    void push(int v, int s, int e) {
        if (all_zero[v]) {
            assert(lz[v] == 0);
            tree[v << 1] = tree[v << 1 | 1] = 0;
            lz[v << 1] = lz[v << 1 | 1] = 0;
            all_zero[v << 1] = all_zero[v << 1 | 1] = true;
        } else if (lz[v] != 0) {
            all_zero[v << 1] = all_zero[v << 1 | 1] = false;
            int mid = (s + e) >> 1;
            tree[v << 1] += 1ll * (mid - s + 1) * lz[v];
            tree[v << 1 | 1] += 1ll * (e - mid) * lz[v];
            lz[v << 1] += lz[v];
            lz[v << 1 | 1] += lz[v];
            lz[v] = 0;
        } else {
            all_zero[v << 1] = all_zero[v << 1 | 1] = false;
        }
    }
    void upd_add(int v, int s, int e, int l, int r, ll val) {
        if (s == l && e == r) {
            all_zero[v] = false;
            tree[v] += 1ll * val * (e - s + 1);
            lz[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd_add(v << 1, s, mid, l, r, val);
        } else if (l >= mid + 1) {
            upd_add(v << 1 | 1, mid + 1, e, l, r, val);
        } else {
            upd_add(v << 1, s, mid, l, mid, val);
            upd_add(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void upd_zero(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            tree[v] = 0;
            all_zero[v] = true;
            lz[v] = 0;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd_zero(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            upd_zero(v << 1 | 1, mid + 1, e, l, r);
        } else {
            upd_zero(v << 1, s, mid, l, mid);
            upd_zero(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    ll get(int v, int s, int e, int idx) {
        if (s == e) {
            return tree[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (idx <= mid) return get(v << 1, s, mid, idx);
        return get(v << 1 | 1, mid + 1, e, idx);
    }
};

void el_psy_congroo() {
    int q;
    cin >> q;
    vector<vector<ll>> queries, adj(q + 5);
    int sz = 1;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            --v;
            adj[v].push_back(sz);
            adj[sz].push_back(v);
            queries.push_back(vector<ll>{sz});
            sz++;
        } else if (t == 2) {
            ll v, x;
            cin >> v >> x;
            --v;
            queries.push_back(vector<ll>{v, x});
        }
    }

    int T = 0;
    vector<int> tin(sz), tout(sz);
    const function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = T++;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
        }
        tout[v] = T++;
    };
    dfs(0, 0);
    assert(T == sz * 2);

    Segtree sgt(sz * 2);
    for (auto e : queries) {
        if (e.size() == 1) {
            sgt.upd_zero(1, 0, 2 * sz - 1, tin[e[0]], tout[e[0]]);
        } else {
            sgt.upd_add(1, 0, 2 * sz - 1, tin[e[0]], tout[e[0]], e[1]);
        }
    }
    for (int i = 0; i < sz; i++) {
        ll ans = sgt.get(1, 0, 2 * sz - 1, tin[i]);
        cout << ans << ' ';
    }
    cout << '\n';
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