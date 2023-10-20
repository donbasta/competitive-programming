#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 320;

void solve() {
    int n, q;
    cin >> n >> q;
    ll ar[n], val[n];
    int par[n], nx[n];
    memset(nx, -1, sizeof(nx));
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        --x;
        par[i + 1] = x;
        adj[i + 1].push_back(x);
        adj[x].push_back(i + 1);
    }
    par[0] = -1;
    int dep[n], cnt_dep[n], id[n];
    memset(cnt_dep, 0, sizeof(cnt_dep));
    const function<void(int, int)> dfs = [&](int v, int p) {
        int tmp = 0;
        for (auto c : adj[v]) {
            if (c == p) continue;
            val[c] = ar[c] * ar[c] + val[v];
            dep[c] = dep[v] + 1;
            id[c] = cnt_dep[dep[c]]++;
            dfs(c, v);
        }
    };
    dep[0] = 0;
    val[0] = ar[0] * ar[0];
    dfs(0, 0);
    vector<vector<ll>> prec(n, vector<ll>(B + 1));
    const function<ll(int, int)> up = [&](int x, int y) -> ll {
        if (x == y) return val[x];
        if (x > y) swap(x, y);
        if (cnt_dep[dep[x]] <= B && prec[x][id[y]]) return prec[x][id[y]];

        ll ans = ar[x] * ar[y] + up(par[x], par[y]);
        if (cnt_dep[dep[x]] <= B) prec[x][id[y]] = ans;
        return ans;
    };
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << up(x, y) << '\n';
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
