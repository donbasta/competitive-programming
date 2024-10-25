#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<int> tree;  // min, max;
    Segtree(int n) : tree(4 * n + 5) {}
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
        return max(
            get(v << 1, s, mid, l, mid),
            get(v << 1 | 1, mid + 1, e, mid + 1, r));
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
    vector<int> tin(n), sz(n), par(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = T++;
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            dfs(c, v);
            sz[v] += sz[c];
        }
    };
    dfs(0, 0);
    Segtree sgt(n);
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        ar[tin[i]] = sz[i];
    }
    sgt.build(1, 0, n - 1, ar);
    vector<bool> ret(n);

    auto find = [&](int l, int r, int mx) -> bool {
        if (l > r) return false;
        return sgt.get(1, 0, n - 1, l, r) >= mx;
    };

    const function<void(int, int)> dfs_reroot = [&](int v, int p) {
        cerr << "rerooting at " << v << " with subtree sizes: \n";
        for (int i = 0; i < n; i++) {
            cerr << i << ' ' << ar[tin[i]] << '\n';
        }

        int idx = -1, sc = 0;
        for (auto c : adj[v]) {
            if (ar[tin[c]] > (n / 2)) {
                sc = ar[tin[c]];
                idx = c;
                break;
            }
        }
        cerr << v << ' ' << idx << ' ' << sc << '\n';
        if (idx == -1)
            ret[v] = true;
        else if (idx == par[v]) {
            int mx = sc - (n / 2);
            ret[v] = find(0, tin[idx] - 1, mx) || find(tin[idx] + 1, tin[v] - 1, mx) || find(tin[v] + sz[v], n - 1, mx);
        } else {
            int mx = sc - (n / 2);
            ret[v] = find(tin[idx] + 1, tin[idx] + sz[idx] - 1, mx);
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            sgt.upd(1, 0, n - 1, tin[c], n);
            sgt.upd(1, 0, n - 1, tin[v], n - sz[c]);
            ar[tin[c]] = n, ar[tin[v]] = n - sz[c];
            dfs_reroot(c, v);
            sgt.upd(1, 0, n - 1, tin[c], sz[c]);
            sgt.upd(1, 0, n - 1, tin[v], n);
            ar[tin[c]] = sz[c], ar[tin[v]] = n;
        }
    };
    dfs_reroot(0, 0);
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
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