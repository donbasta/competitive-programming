#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n);
    vector<int> par(n, -1);
    const function<void(int, int)> dfs_size = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            dfs_size(c, v);
            sz[v] += sz[c];
        }
    };
    dfs_size(0, 0);
    vector<ll> M(n);
    for (int i = 1; i < n; i++) {
        M[0] += 1ll * (ar[i] ^ ar[par[i]]) * sz[i];
    }

    const function<void(int, int)> dfs_reroot = [&](int v, int p) {
        for (auto c : adj[v]) {
            if (c == p) continue;
            M[c] = M[v] - 1ll * (ar[c] ^ ar[v]) * sz[c];
            M[c] += 1ll * (ar[c] ^ ar[v]) * (n - sz[c]);
            dfs_reroot(c, v);
        }
    };
    dfs_reroot(0, 0);
    for (int i = 0; i < n; i++) {
        cout << M[i] << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}