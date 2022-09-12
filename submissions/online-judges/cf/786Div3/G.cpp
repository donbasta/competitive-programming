#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    set<pair<int, int>> edges;
    vector<int> out(n), in(n), f(n, -1), g(n, -1), bf(n), bg(n);
    vector<bool> sf(n), sg(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        edges.emplace(v, u);
        out[v]++, in[u]++;
        f[v] = u, g[u] = v;
    }
    for (int i = 0; i < n; i++) {
        if (out[i] == 1) {
            out[i] = 0;
            sf[i] = true;
            bf[f[i]]++;
            edges.erase(make_pair(i, f[i]));
        }
        if (in[i] == 1) {
            in[i] = 0;
            sg[i] = true;
            bg[g[i]]++;
            edges.erase(make_pair(g[i], i));
        }
    }
    for (int i = 0; i < n; i++) {
        if (!sg[i]) in[i] -= bf[i];
        if (!sf[i]) out[i] -= bg[i];
    }
    for (auto e : edges) {
        to[e.second].emplace_back(e.first);
    }
    queue<int> Q;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        if (out[i] == 0) {
            Q.emplace(i);
            dp[i] = 1;
        }
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (auto i : to[now]) {
            dp[i] = max(dp[i], dp[now] + 1);
            out[i]--;
            if (out[i] == 0) {
                Q.emplace(i);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
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