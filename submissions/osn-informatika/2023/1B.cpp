#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 0; i < n; i++) {
        int sz = adj[i].size();
        if (sz == 0) {
            ans += 1ll * (i + 1) * (n - i);
            continue;
        }
        int L = -1, R = n;
        int x = upper_bound(adj[i].begin(), adj[i].end(), i) - adj[i].begin();
        int y = x - 1;
        if (x < sz) R = adj[i][x];
        if (y >= 0) L = adj[i][y];
        long long add = 1ll * (R - i) * (i - L);
        ans += add;
    }
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1];
        int su = adj[u].size(), sv = adj[v].size();
        int x = upper_bound(adj[u].begin(), adj[u].end(), u) - adj[u].begin();
        int y = upper_bound(adj[v].begin(), adj[v].end(), v) - adj[v].begin() - 1;
        if (x < su && adj[u][x] < v) {
            continue;
        }
        if (y >= 0 && adj[v][y] > u) {
            continue;
        }
        y++, x--;
        int z = upper_bound(adj[u].begin(), adj[u].end(), v) - adj[u].begin();
        int w = lower_bound(adj[v].begin(), adj[v].end(), u) - adj[v].begin() - 1;
        int L = -1, R = n;
        if (x >= 0) L = max(L, adj[u][x]);
        if (w >= 0) L = max(L, adj[v][w]);
        if (y < sv) R = min(R, adj[v][y]);
        if (z < su) R = min(R, adj[u][z]);
        long long add = 2ll * (u - L) * (R - v);
        ans += add;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}