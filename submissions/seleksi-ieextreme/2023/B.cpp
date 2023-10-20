#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n, m, x, a, b;
    cin >> n >> m >> x >> a >> b;
    --a, --b;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll k;
        cin >> u >> v >> k;
        --u, --v;
        adj[u].emplace_back(v, k);
        adj[v].emplace_back(u, k);
    }

    vector<ll> d(n, INF);
    d[a] = 0;
    set<pair<ll, int>> q;
    q.insert({0, a});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
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