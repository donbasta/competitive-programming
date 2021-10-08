#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;

void solve() {
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<vector<ll>> path(n + 1, vector<ll>(k));
    vector<ll> sz(n + 1), sum(n + 1), dp(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    ll ans = 0;
    const auto dfs = [&](const auto& self, int v, int p) -> void {
        vector<ll> tmp(k);
        vector<ll> md(k);
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            self(self, c, v);
            for (int i = 0; i < k; i++) {
                tmp[i] += path[c][i];
            }
            sz[v] += sz[c];
            dp[v] += dp[c];
            dp[v] += (sum[c] + sz[c]);
            sum[v] += (sum[c] + sz[c]);
        }
        ll lol = 0;
        for (auto c : adj[v]) {
            if (c == p) continue;
            lol += (sum[c] + sz[c]) * (sz[v] - sz[c] - 1);
        }
        dp[v] += lol;
        for (auto c : adj[v]) {
            if (c == p) continue;
            for (int i = 0; i < k; i++) {
                md[(i + 1) % k] += path[c][i] * 2;
                for (int j = 0; j < k; j++) {
                    md[(i + j + 2) % k] += path[c][i] * (tmp[j] - path[c][j]);
                }
            }
        }
        for (int i = 0; i < k; i++) {
            md[i] /= 2;
            ll add = (i == 0 ? 0 : k - i);
            ans += add * md[i];
        }
        for (int i = 0; i < k; i++) {
            path[v][i] = tmp[(i + k - 1) % k];
        }
        path[v][0]++;
    };

    dfs(dfs, 1, 1);

    ans += dp[1];
    assert(ans % k == 0);
    ans /= k;
    cout << ans << '\n';
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