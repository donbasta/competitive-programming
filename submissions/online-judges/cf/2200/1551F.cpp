#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 100;

int n, k;
int C[N + 5][N + 5];

void init_combi() {
    for (int i = 0; i <= N; i++) {
        C[i][0] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

struct Graph {
    int n;
    vector<vector<int>> adj;
    Graph(int n) : n(n) {
        adj.resize(n + 1);
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>& operator[](int u) {
        return adj[u];
    }
    int calc_root(int root) {
        vector<int> ans(n + 1);
        const auto dfs = [&](const auto &self, int v, int p, int d) -> void {
            int ret = 0;
            vector<int> dep(n + 1);
            const auto dfs1 = [&](const auto &self1, int v, int p, int d) -> void {
                dep[d]++;
                for (int c : adj[v]) {
                    if (c == p) continue;
                    self1(self1, c, v, d + 1);
                }
            };
            dfs1(dfs1, v, p, d);
            for (int i = 1; i <= n; i++) {
                ret = (ret + C[dep[i]][k]) % MOD;
            }
            for (int c : adj[v]) {
                if (c == p) continue;
                self(self, c, v, d + 1);
                ret = (ret - ans[c]) % MOD;
                if (ret < 0) ret += MOD;
            }
            ans[v] = ret;  
        };
        dfs(dfs, root, 0, 0);
        return ans[root];
    }
};

void solve() {
    cin >> n >> k;

    Graph g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }

    ll ans = 0;
    if (k == 2) {
        ans = n * (n - 1) / 2;
        cout << ans << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        ans = (ans + g.calc_root(i)) % MOD;
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_combi();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}