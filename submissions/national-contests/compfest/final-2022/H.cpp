#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> par(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        cin >> par[i];
        --par[i];
        adj[par[i]].push_back(i);
    }

    vector<int> dp(n, 0);
    const function<void(int)> dfs = [&](int v) {
        for (auto c : adj[v]) {
            dfs(c);
            dp[v] += dp[c];
        }
        if (adj[v].size() <= 1) {
            dp[v]++;
        }
    };
    dfs(0);
    cout << dp[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}