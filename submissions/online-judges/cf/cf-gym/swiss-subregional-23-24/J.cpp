#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll n, m, k, y;
    cin >> n >> m >> k >> y;
    --y;

    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        ll u, v, e;
        cin >> u >> v >> e;
        --u, --v;
        adj[v].emplace_back(u, e);
    }

    vector<vector<pair<ll, ll>>> adj2(n);
    vector<ll> vis(n), in(n);
    bool ada_scc = false;
    const function<void(int, int)> dfs = [&](int v, int p) {
        vis[v] = 1;
        for (auto c : adj[v]) {
            adj2[v].emplace_back(c);
            in[c.first]++;
            if (c.first == p || vis[c.first] == 1) {
                ada_scc = true;
                continue;
            }
            if (vis[c.first] == 2) continue;
            dfs(c.first, v);
        }
        vis[v] = 2;
    };
    dfs(y, -1);
    if (ada_scc) {
        cout << "YES" << '\n';
        return;
    }
    vector<ll> dp(n);
    queue<int> Q;
    Q.emplace(y);
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : adj2[now]) {
            dp[c.first] = max(dp[c.first], dp[now] + c.second);
            in[c.first]--;
            if (in[c.first] == 0) {
                Q.emplace(c.first);
            }
        }
    }
    cout << ((*max_element(dp.begin(), dp.end()) >= k) ? "YES" : "NO") << '\n';
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