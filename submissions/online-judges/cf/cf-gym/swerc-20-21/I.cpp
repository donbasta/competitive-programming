#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cerr << "TES" << '\n';

    int diam = INT_MAX;
    // int u = rand() % n;
    int u = 0;
    // cerr << u << '\n';
    while (true) {
        vector<int> dis(n, INT_MAX);
        vector<bool> vis(n);
        dis[u] = 0;
        vis[u] = true;
        queue<int> Q;
        Q.emplace(u);
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : adj[now]) {
                if (vis[c]) continue;
                dis[c] = dis[now] + 1;
                vis[c] = true;
                Q.emplace(c);
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cerr << i << ' ' << dis[i] << '\n';
        // }
        auto ptr = max_element(dis.begin(), dis.end());
        int mx = *ptr;
        // cerr << (*ptr) << '\n';
        if (mx == INT_MAX) {
            cout << -1 << '\n';
            return;
        }
        if (mx < diam) {
            diam = mx;
            u = ptr - dis.begin();
        } else {
            break;
        }
    }
    // cerr << diam << '\n';
    int ans = 0, d = 1;
    while (d < diam) {
        ans++, d <<= 1;
    }
    cout << ans + 1 << '\n';
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