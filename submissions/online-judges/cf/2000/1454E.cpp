#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) : n(_n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.assign(n + 1, 1);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x);
        y = fpar(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        par[y] = x;
        sz[x] += sz[y];
    }
};

int n;

void solve() {
    cin >> n;

    DSU dsu = DSU(n);

    vector<vector<int>> adj(n + 1);
    vector<int> ve;

    const auto find_path = [&](const auto& self, int from, int to, int par) -> bool {
        if (from == to) {
            ve.emplace_back(to);
            return true;
        }
        for (auto c : adj[from]) {
            if (c == par) {
                continue;
            }
            if (self(self, c, to, from)) {
                ve.emplace_back(from);
                return true;
            }
        }
        return false;
    };

    bool belum = true;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if ((dsu.fpar(u) == dsu.fpar(v)) && belum) {
            assert(find_path(find_path, u, v, u));
            reverse(ve.begin(), ve.end());
            belum = false;
        } else {
            dsu.merge(u, v);
        }
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    ll ans = 1LL * n * (n - 1);
    int sz = (int) ve.size();

    int nx, pr;
    const auto dfs = [&](const auto& self, int v, int p) -> int {
        int ret = 1;
        for (auto c : adj[v]) {
            if (c == p || c == nx || c == pr) continue;
            ret += self(self, c, v);
        }
        return ret;
    };
    for (int i = 0; i < sz; i++) {
        nx = ve[(i + 1) % sz];
        pr = ve[(i + sz - 1) % sz];
        int sz = dfs(dfs, ve[i], ve[i]);
        ans -= (1LL * sz * (sz - 1) / 2);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}