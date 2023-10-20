#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

struct Segtree {
    vector<int> tree, lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void push(int v, int s, int e) {
        if (lz[v]) {
            lz[v << 1] = (lz[v << 1] + lz[v]) % MOD;
            lz[v << 1 | 1] = (lz[v << 1 | 1] + lz[v]) % MOD;
            int mid = (s + e) >> 1;
            tree[v << 1] = (1ll * tree[v << 1] + 1ll * (mid - s + 1) * lz[v]) % MOD;
            tree[v << 1 | 1] = (1ll * tree[v << 1 | 1] + 1ll * (e - mid) * lz[v]) % MOD;
            lz[v] = 0;
        }
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = (tree[v << 1] + tree[v << 1 | 1]) % MOD;
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            lz[v] = (lz[v] + val) % MOD;
            tree[v] = (1ll * tree[v] + 1ll * val * (e - s + 1)) % MOD;
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
        tree[v] = (tree[v << 1] + tree[v << 1 | 1]) % MOD;
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
        return (get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r)) % MOD;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> depth(n);
    vector<int> par(n, -1);
    const function<void(int, int, int)> dfs = [&](int v, int p, int d) {
        depth[d].push_back(v);
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            dfs(c, v, d + 1);
        }
    };
    dfs(0, 0, 0);

    vector<int> id(n);
    int cur = 0;
    id[0] = cur++;
    vector<int> L(n, -1), R(n, -1);
    for (int i = 1; i < n; i++) {
        int sz = depth[i].size();
        if (sz == 0) break;
        int cur_par = par[depth[i][0]];
        id[depth[i][0]] = cur++;
        int st = id[depth[i][0]];
        for (int j = 1; j < sz; j++) {
            if (par[depth[i][j]] != cur_par) {
                L[cur_par] = st;
                R[cur_par] = id[depth[i][j - 1]];
                cur_par = par[depth[i][j]];
                id[depth[i][j]] = cur++;
                st = id[depth[i][j]];
            } else {
                id[depth[i][j]] = cur++;
            }
        }
        L[cur_par] = st;
        R[cur_par] = id[depth[i][sz - 1]];
    }

    vector<int> T(n);
    for (int i = 0; i < n; i++) T[id[i]] = ar[i];
    Segtree sgt(n);
    sgt.build(1, 0, n - 1, T);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            int cur = sgt.get(1, 0, n - 1, id[x], id[x]);
            if (L[x] != -1) {
                sgt.upd(1, 0, n - 1, L[x], R[x], cur);
            }
            if (x != 0) {
                sgt.upd(1, 0, n - 1, id[par[x]], id[par[x]], cur);
            }
        } else {
            int sum = 0;
            if (L[x] != -1) {
                sum = (sum + sgt.get(1, 0, n - 1, L[x], R[x])) % MOD;
            }
            if (x != 0) {
                sum = (sum + sgt.get(1, 0, n - 1, id[par[x]], id[par[x]])) % MOD;
            }
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