#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n), sz(n), par(n), dep(n);
    vector<int> st(4 * n + 5), id(n), tp(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> prf(n);
    const function<void(int, int)> upd = [&](int l, int r) {
        prf[l]++;
        if (r + 1 < n) prf[r + 1]--;
    };
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

    const function<void(int, int)> upd_path = [&](int x, int y) -> void {
        while (tp[x] != tp[y]) {
            if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
            upd(id[tp[x]], id[x]);
            x = par[tp[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        upd(id[x], id[y]);
    };

    dfs_sz(0, 0);
    dfs_hld(0, 0, 0);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        upd_path(a, b);
    }
    for (int i = 1; i < n; i++) {
        prf[i] += prf[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << prf[id[i]] << ' ';
    }
    cout << '\n';
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