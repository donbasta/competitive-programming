#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int K = 20;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> par(n, 0), tin(n, -1), tout(n, -1), depth(n);
    vector<vector<int>> adj(n);
    int timer = 0;
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        tin[v] = timer++;
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            depth[c] = depth[v] + 1;
            dfs(c, v);
        }
        tout[v] = timer++;
    };
    dfs(0, 0);
    vector<vector<int>> up(n, vector<int>(K));
    for (int i = 0; i < n; i++) {
        up[i][0] = par[i];
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    const function<bool(int, int)> is_ancestor = [&](int x, int y) -> bool {
        return ((tin[x] <= tin[y]) && (tout[x] >= tout[y]));
    };
    const function<int(int, int)> lca = [&](int x, int y) -> int {
        if (is_ancestor(x, y)) return x;
        if (is_ancestor(y, x)) return y;
        int cur = x;
        for (int b = K - 1; b >= 0; b--) {
            if (!is_ancestor(up[cur][b], y)) {
                cur = up[cur][b];
            }
        }
        return up[cur][0];
    };
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int c = lca(a, b);
        int dis = depth[a] + depth[b] - 2 * depth[c];
        cout << dis << '\n';
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