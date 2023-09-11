#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, x;
    cin >> n >> x;
    --x;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> par(n, -1), mx_depth(n), dis(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            dis[c] = dis[v] + 1;
            dfs(c, v);
            mx_depth[v] = max(mx_depth[v], mx_depth[c] + 1);
        }
    };
    dfs(0, 0);
    int ans = dis[x] + mx_depth[x];
    int cur = x;
    cur = par[cur];
    while (cur != -1) {
        int b = dis[x] - dis[cur];
        int a = dis[cur];
        if (b < a) {
            ans = max(ans, dis[cur] + mx_depth[cur]);
        }
        cur = par[cur];
    }
    cout << 2 * ans << '\n';
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