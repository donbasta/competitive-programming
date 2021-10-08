#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m, s;

void solve() {
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    vector<vector<bool>> can(n + 1, vector<bool>(n + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    const auto dfs = [&](const auto& self, int v, int pr) -> void {
        can[pr][v] = true;
        vis[pr][v] = true;
        for (auto c : adj[v]) {
            if (!vis[pr][c]) {
                self(self, c, pr);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        dfs(dfs, i, i);
    }
    vector<pair<int, int>> cant;
    for (int i = 1; i <= n; i++) {
        if (!can[s][i]) {
            cant.emplace_back(i, 0);
        }
    }
    if (cant.empty()) {
        cout << 0 << '\n';
        return;
    }

    int sz = (int) cant.size();
    vector<vector<int>> ve(sz);
    for (int i = 0; i < sz; i++) {
        int tmp = 0;
        for (int j = 0; j < sz; j++) {
            if (can[cant[i].first][cant[j].first]) {
                tmp++;
            }
        }
        cant[i].second = tmp;
    }

    sort (cant.begin(), cant.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (can[cant[i].first][cant[j].first]) {
                ve[i].emplace_back(j);
            }
        }
    }

    vector<bool> udah(sz);
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        if (udah[i]) {
            continue;
        }
        ans++;
        udah[i] = true;
        for (auto e : ve[i]) {
            udah[e] = true;
        }
    }

    cout << ans << '\n';
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