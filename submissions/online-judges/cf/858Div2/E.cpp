#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 350;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> ar(n);
    vector<int> par(n), nx(n, -1);
    vector<vector<int>> adj(n);
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
    vector<int> dep(n), cnt_dep(n);
    vector<vector<int>> layer(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        for (auto c : adj[v]) {
            if (c == p) continue;
            dep[c] = dep[v] + 1;
            dfs(c, v);
        }
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        cnt_dep[i]++;
        layer[dep[i]].push_back(i);
    }
    unordered_map<ll, ll> prec;
    auto f = [&](int p, int q) -> ll {
        return ((1ll * p) << 20) + q;
    };
    for (int i = 0; i < n; i++) {
        if (cnt_dep[i] <= B) {
            int sz = layer[i].size();
            sort(layer[i].begin(), layer[i].end());
            for (int p = 0; p < sz; p++) {
                for (int q = p; q < sz; q++) {
                    int pp = layer[i][p], qq = layer[i][q];
                    prec[f(pp, qq)] = 1ll * ar[pp] * ar[qq];
                    nx[pp] = pp, nx[qq] = qq;
                    if (pp && qq && prec.find(f(par[pp], par[qq])) != prec.end()) {
                        prec[f(pp, qq)] += prec[f(par[pp], par[qq])];
                        nx[pp] = nx[par[pp]], nx[qq] = nx[par[qq]];
                    }
                }
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        ll ans = 0;
        while ((x != -1) && (y != -1)) {
            if (x > y) swap(x, y);
            if (cnt_dep[dep[x]] <= B) {
                ans += prec[f(x, y)];
                x = nx[x], y = nx[y];
            } else {
                ans += ar[x] * ar[y];
            }
            x = par[x], y = par[y];
        }
        cout << ans << '\n';
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