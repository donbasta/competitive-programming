#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    map<int, pair<int, int>> edges;
    map<pair<int, int>, int> edge_mult;
    for (int i = 0; i < n - 1; i++) {
        int u, v, m;
        cin >> u >> v >> m;
        --u, --v;
        adj[u].emplace_back(v, m);
        adj[v].emplace_back(u, m);
        if (u > v) swap(u, v);
        edges[i] = make_pair(u, v);
        edge_mult[make_pair(u, v)] = m;
    }

    vector<int> turun(n), naik(n);

    int ans = 0;

    const function<void(int, int)> dfs = [&](int v, int p) {
        turun[v] = 1;
        naik[v] = 1;
        for (auto c : adj[v]) {
            if (c.first == p) continue;
            dfs(c.first, v);
            int T = 0, N = 0;
            int a = c.first, b = v;
            if (a > b) swap(a, b);
            int cost = edge_mult[make_pair(a, b)];
            if (w[c.first] <= w[v]) {
                T = (1ll * cost * turun[c.first]) % MOD;
            }
            if (w[c.first] >= w[v]) {
                N = (1ll * cost * naik[c.first]) % MOD;
            }

            ans = (1ll * T * naik[v] + ans) % MOD;
            ans = (1ll * N * turun[v] + ans) % MOD;
            turun[v] = (turun[v] + T) % MOD;
            naik[v] = (naik[v] + N) % MOD;
        }
    };

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        ans = 0;
        if (t == 1) {
            --x;
            w[x] = y;
        } else if (t == 2) {
            --x;
            edge_mult[edges[x]] = y;
        }
        dfs(0, 0);
        cout << ans + n << '\n';
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