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
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (adj[0].size() == 1) {
        cout << 1 << '\n';
        return;
    }

    vector<int> sz(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            sz[v] += sz[c];
        }
    };
    dfs(0, 0);
    int tmp = 0, mx = -1;
    for (auto c : adj[0]) {
        tmp += sz[c];
        mx = max(mx, sz[c]);
    }
    tmp -= mx;
    cout << (tmp + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}