#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n, vector<ll>(n, -1));

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][v] = adj[v][u] = w;
    }

    int mx_mask = 1;
    ll ans = k;
    for (int i = 0; i < n - 1; i++) mx_mask *= n;

    auto gen = [&](int mask) -> vector<int> {
        vector<int> ret;
        for (int i = 0; i < n - 1; i++) {
            ret.push_back(mask % n);
            mask /= n;
        }
        return ret;
    };

    vector<int> par(n);
    const function<int(int)> fpar = [&](int x) -> int {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    };
    auto merge = [&](int x, int y) -> bool {
        x = fpar(x), y = fpar(y);
        if (x == y) return false;
        par[x] = y;
        return true;
    };

    for (int i = 0; i < mx_mask; i++) {
        iota(par.begin(), par.end(), 0);
        vector<int> to = gen(i);
        bool cant = false;
        ll tmp = 0;
        for (int j = 0; j < n - 1; j++) {
            if (adj[j][to[j]] == -1) {
                cant = true;
                break;
            }
            if (!merge(j, to[j])) {
                cant = true;
                break;
            }
            tmp = (tmp + adj[j][to[j]]) % k;
        }
        if (!cant) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << '\n';
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