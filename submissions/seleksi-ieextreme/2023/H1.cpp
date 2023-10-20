#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> dig(n);
    for (int i = 0; i < n; i++) {
        cin >> dig[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    vector<vector<vector<int>>> up(n, vector<vector<int>>(2, vector<int>(11)));
    vector<vector<vector<int>>> down(n, vector<vector<int>>(2, vector<int>(11)));
    const function<void(int, int)> dfs = [&](int v, int p) {
        up[v][1][dig[v]] = down[v][1][dig[v]] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            for (int j = 0; j < 11; j++) {
                int jj = (11 - j) % 11;
                ans += 1ll * up[c][0][j] * down[v][0][jj];
                ans += 1ll * up[c][0][j] * down[v][1][jj];
                ans += 1ll * up[c][1][j] * down[v][0][j];
                ans += 1ll * up[c][1][j] * down[v][1][j];

                ans += 1ll * up[v][0][j] * down[c][0][jj];
                ans += 1ll * up[v][0][j] * down[c][1][jj];
                ans += 1ll * up[v][1][j] * down[c][0][j];
                ans += 1ll * up[v][1][j] * down[c][1][j];
            }
            for (int j = 0; j < 11; j++) {
                int x = (j + dig[v]) % 11;
                int y = (j - dig[v]) % 11;
                if (y < 0) y += 11;
                int z = (dig[v] - j) % 11;
                if (z < 0) z += 11;
                up[v][0][j] += up[c][1][x];
                up[v][1][j] += up[c][0][y];
                down[v][0][j] += down[c][1][z];
                down[v][1][j] += down[c][0][z];
            }
        }
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        ans += (dig[i] == 0);
    }
    cout << ans << '\n';
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