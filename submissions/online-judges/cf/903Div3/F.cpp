#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<bool> col(n);
    vector<vector<int>> adj(n);
    int st = -1;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        --x;
        col[x] = true;
        st = x;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> dis(n);
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        for (auto c : adj[v]) {
            if (c == p) continue;
            dis[c] = dis[v] + 1;
            dfs(c, v);
        }
    };

    dfs(st, -1);
    int mx = 0;
    st = -1;
    for (int i = 0; i < n; i++) {
        if (!col[i]) continue;
        if (dis[i] > mx) {
            mx = dis[i];
            st = i;
        }
    }
    fill(dis.begin(), dis.end(), 0);
    dfs(st, -1);
    mx = -1;
    for (int i = 0; i < n; i++) {
        if (!col[i]) continue;
        if (dis[i] > mx) {
            mx = dis[i];
        }
    }
    int ans = (mx + 1) / 2;
    cout << ans << '\n';
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