#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n), col(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v), adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    const function<void(int, int)> dfs = [&](int v, int p) {
        for (auto c : adj[v]) {
            if (c == p) continue;
            col[c] = col[v] ^ 1;
            dfs(c, v);
        }
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        int ret = deg[i] * (2 * col[i] - 1);
        cout << ret << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}