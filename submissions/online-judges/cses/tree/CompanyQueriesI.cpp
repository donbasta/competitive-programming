#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int K = 20;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> par(n, 0), dep(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 1; i <= n - 1; i++) {
        int x;
        cin >> x;
        --x;
        par[i] = x;
        adj[x].push_back(i), adj[i].push_back(x);
    }
    vector<vector<int>> up(n, vector<int>(K));
    for (int i = 0; i < n; i++) {
        up[i][0] = par[i];
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        for (auto c : adj[v]) {
            if (c == p) continue;
            dep[c] = dep[v] + 1;
            dfs(c, v);
        }
    };
    dfs(0, 0);
    const function<int(int, int)> kth_ancestor = [&](int v, int k) -> int {
        int cur = v;
        for (int i = K - 1; i >= 0; i--) {
            if ((k >> i) & 1) {
                cur = up[cur][i];
            }
        }
        return cur;
    };
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        --x;
        if (dep[x] < k) {
            cout << -1 << '\n';
        } else {
            cout << (kth_ancestor(x, k) + 1) << '\n';
        }
    }
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