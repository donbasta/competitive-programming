#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct DSU {
    int n;
    vector<int> par;
    vector<int> sz;
    vector<bool> can;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        can.assign(n, false);
    }
    int fpar(int n) {
        if (n == par[n]) return n;
        return par[n] = fpar(par[n]);
    }
    void merge(int a, int b) {
        a = fpar(a), b = fpar(b);
        if (a == b) return;
        if (sz[a] > sz[b]) {
            par[b] = a;
            sz[a] += sz[b];
            can[a] = can[a] || can[b];
        } else {
            par[a] = b;
            sz[b] += sz[a];
            can[b] = can[b] || can[a];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        ve.emplace_back(ar[i], i);
    }
    sort(ve.begin(), ve.end());
    vector<int> mp(n);
    for (int i = 0; i < n; i++) {
        mp[ve[i].second] = i;
    }

    vector<vector<int>> adj(n);
    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[mp[u]].push_back(mp[v]);
        adj[mp[v]].push_back(mp[u]);
        if (ar[mp[u]] == ar[mp[v]]) {
            edges[ar[mp[u]]].emplace_back(mp[u], mp[v]);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    DSU dsu(n);
    vector<int> ptr(n);

    int cur = ve[0].first;
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (ve[i].first != cur) {
            bool ok = false;
            for (int j = last; j < i; j++) {
                int awal = ptr[j];
                while (ptr[j] < adj[j].size() && adj[j][ptr[j]] < last) {
                    int x = dsu.fpar(adj[j][ptr[j]]);
                    if (dsu.sz[x] < cur) {
                        dsu.can[x] = false;
                    }
                    if (dsu.sz[x] >= cur && dsu.can[x]) {
                        ok = true;
                    }
                    ptr[j]++;
                }
                for (int k = awal; k < ptr[j]; k++) {
                    dsu.merge(j, adj[j][k]);
                }
            }
            if (cur == 0) {
                for (int j = last; j < i; j++) dsu.can[j] = true;
            }
            for (auto e : edges[cur]) {
                dsu.merge(e.first, e.second);
            }
            if (!ok && (cur > 0)) {
                cout << "No" << '\n';
                return;
            }
            cur = ve[i].first;
            last = i;
        }
    }
    {
        bool ok = false;
        for (int j = last; j < n; j++) {
            int awal = ptr[j];
            while (ptr[j] < adj[j].size() && adj[j][ptr[j]] < last) {
                int x = dsu.fpar(adj[j][ptr[j]]);
                if (dsu.sz[x] < cur) {
                    dsu.can[x] = false;
                }
                if (dsu.sz[x] >= cur && dsu.can[x]) {
                    ok = true;
                }
                ptr[j]++;
            }
            for (int k = awal; k < ptr[j]; k++) {
                dsu.merge(j, adj[j][k]);
            }
        }
        if (cur == 0) {
            for (int j = last; j < n; j++) dsu.can[j] = true;
        }
        for (auto e : edges[cur]) {
            dsu.merge(e.first, e.second);
        }
        if (!ok && (cur > 0)) {
            cout << "No" << '\n';
            return;
        }
    }
    set<int> se;
    for (int i = 0; i < n; i++) {
        se.insert(dsu.fpar(i));
    }
    if (se.size() != 1) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    return;
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