#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p) {
            adj[i].emplace_back(p);
            adj[p].emplace_back(i);
        }
    }
    if (n % 2 == 0) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> sz(n + 1, 1);
    const auto dfs1 = [&](const auto& self, int v, int p) -> void {
        for (auto c : adj[v]) {
            if (c == p) continue;
            self(self, c, v);
            sz[v] += sz[c];
        }
    };
    dfs1(dfs1, 1, 1);

    vector<int> ans;
    vector<bool> vis(n + 1);
    const auto dfs2 = [&](const auto& self, int v, int p) -> void {
        if (vis[v]) return;
        vis[v] = true;
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (sz[c] % 2 == 0) self(self, c, v);
        }
        ans.emplace_back(v);
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (sz[c] % 2 == 1) self(self, c, v);
        }
    };
    dfs2(dfs2, 1, 1);

    cout << "YES" << '\n';
    for (auto e : ans) {
        cout << e << '\n';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}