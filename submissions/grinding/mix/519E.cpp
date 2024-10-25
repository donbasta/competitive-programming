#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int B = 20;

void el_psy_congroo() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> tin(n), tout(n), dep(n), sz(n);
    vector<vector<int>> up(n, vector<int>(B));
    int T = 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        tin[v] = T++;
        sz[v] = 1;
        up[v][0] = p;
        for (int i = 1; i < B; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            dep[c] = dep[v] + 1;
            dfs(c, v);
            sz[v] += sz[c];
        }
        tout[v] = T++;
    };
    dfs(0, 0);

    const auto is_ancestor = [&](int a, int b) -> bool {
        return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
    };
    const auto lca = [&](int a, int b) -> int {
        if (is_ancestor(a, b)) return a;
        if (is_ancestor(b, a)) return b;
        for (int i = B - 1; i >= 0; i--) {
            if (!is_ancestor(up[b][i], a)) {
                b = up[b][i];
            }
        }
        return up[b][0];
    };
    const auto dis = [&](int a, int b) -> int {
        return dep[a] + dep[b] - 2 * dep[lca(a, b)];
    };
    const auto ascend = [&](int v, int k) -> int {
        for (int i = B - 1; i >= 0; i--) {
            if (k >= (1 << i)) {
                v = up[v][i];
                k -= (1 << i);
            }
        }
        return v;
    };

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (x == y) {
            cout << n << '\n';
            continue;
        }
        int L = lca(x, y);
        int D = dis(x, y);
        if (D & 1) {
            cout << 0 << '\n';
            continue;
        }
        int dx = dis(x, L), dy = dis(y, L);
        if (dx == dy) {
            int u = ascend(x, dx - 1);
            int v = ascend(y, dy - 1);
            cout << (n - sz[u] - sz[v]) << '\n';
            continue;
        } else if (dx < dy) {
            int piv = ascend(y, D / 2);
            int cpiv = ascend(y, D / 2 - 1);
            cout << (sz[piv] - sz[cpiv]) << '\n';
        } else if (dx > dy) {
            int piv = ascend(x, D / 2);
            int cpiv = ascend(x, D / 2 - 1);
            cout << (sz[piv] - sz[cpiv]) << '\n';
        }
    }
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