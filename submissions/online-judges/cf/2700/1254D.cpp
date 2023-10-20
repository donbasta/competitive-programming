#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int n, q;
const int M = 150000 + 5;

void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int bit[M];
void point_add(int idx, int val) {
    while (idx <= n) {
        add(bit[idx], val);
        idx += idx & -idx;
    }
}

void range_add(int l, int r, int val) {
    point_add(l, val);
    point_add(r + 1, MOD - val);
}

int query(int idx) {
    int ret = 0;
    while (idx > 0) {
        add(ret, bit[idx]);
        idx -= idx & -idx;
    }
    return ret;
}

int val[M], sz[M], in[M], out[M], par[M];
vector<int> adj[M];
int T = 0;

void dfs_sz(int v, int p) {
    sz[v] = 1;
    for (auto c : adj[v]) {
        if (c == p) continue;
        par[c] = v;
        dfs_sz(c, v);
        sz[v] += sz[c];
    }
};
void dfs_euler(int v, int p) {
    in[v] = T++;
    for (auto c : adj[v]) {
        if (c == p) continue;
        dfs_euler(c, v);
    }
    out[v] = T;
};

void solve() {
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Segtree sgt(n);
    dfs_sz(0, 0);
    vector<pair<int, int>> ve[n];  // val, count
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        sort(adj[i].begin(), adj[i].end(), [&](int x, int y) -> bool {
            return sz[x] > sz[y];
        });
        for (auto c : adj[i])
            if (c == par[i])
                continue;
            else
                tmp.push_back(c);
        if (tmp.empty()) continue;
        int siz = tmp.size();
        int last = 0;
        for (int j = 1; j < siz; j++) {
            if (sz[tmp[j]] != sz[tmp[j - 1]]) {
                ve[i].emplace_back(sz[tmp[j - 1]], j - last);
                last = j;
            }
        }
        ve[i].emplace_back(sz[tmp[siz - 1]], siz - last);
    }
    dfs_euler(0, 0);

    int inv = fpow(n, MOD - 2);
    for (int i = 0; i < q; i++) {
        int t, v, d;
        cin >> t;
        if (t == 1) {
            cin >> v >> d;
            if (d == 0) continue;
            --v;
            int l = in[v], r = out[v] - 1;
            int luar = (1ll * d * sz[v]) % MOD;
            luar = (1ll * luar * inv) % MOD;
            if (l >= 1) range_add(1, l, luar);
            if (n - 1 >= r + 1) range_add(r + 2, n, luar);
            range_add(l + 1, l + 1, d);
            l++;
            for (auto c : ve[v]) {
                int xx = (1ll * d * (n - c.first)) % MOD;
                xx = (1ll * xx * inv) % MOD;
                range_add(l + 1, l + c.second * c.first, xx);
                l = l + c.second * c.first;
            }
            assert(l == out[v]);
        } else if (t == 2) {
            cin >> v;
            --v;
            cout << query(in[v] + 1) << '\n';
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