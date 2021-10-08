#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;

void solve() {
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    vector<int> xr(n + 1), ar(n + 1);
    int all = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        all ^= ar[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (all == 0) {
        cout << "YES" << '\n';
        return;
    }
    if (k == 2) {
        cout << "NO" << '\n';
        return;
    }

    int timer = 0;
    vector<int> tin(n + 1), tout(n + 1);
    vector<int> candidates, checks;
    vector<bool> ada(n + 1);
    bool ok = false;
    const auto dfs = [&](const auto& self, int v, int p) -> void {
        tin[v] = ++timer;
        int tmp = ar[v];
        for (auto c : adj[v]) {
            if (c == p) continue;
            self(self, c, v);
            ada[v] = (ada[v] | ada[c] | (xr[c] == all));
            tmp ^= xr[c];
        }
        xr[v] = tmp;
        if ((xr[v] == all)) {
            candidates.emplace_back(v);
            checks.emplace_back(tin[v]);
        }
        if ((xr[v] == 0) && ada[v]) {
            ok = true;
        }
        tout[v] = ++timer;
    };
    dfs(dfs, 1, 1);
    sort(checks.begin(), checks.end());
    int sz = (int) candidates.size();
    for (auto e : candidates) {
        int a = upper_bound(checks.begin(), checks.end(), tout[e]) - checks.begin();
        if (a < sz) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}