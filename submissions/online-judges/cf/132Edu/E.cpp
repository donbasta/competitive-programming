#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> dp(n + 1);
    const auto dfs = [&](const auto& self, int v, int p) -> {
        int path = 0;
        for (auto c : adj[v]) {
            if (c == p) continue;
            self(self, c, v);
            path += dp[c];
        }
        //find a new path involving v
        dp[v] = path;
    };
    dfs(dfs, 1, 1);
    cout << dp[1] << '\n';
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
