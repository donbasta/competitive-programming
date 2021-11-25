#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 2e9;

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) : n(_n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        sz.assign(n + 1, 1);
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    void merge(int x, int y) {
        x = fpar(x);
        y = fpar(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        par[y] = x;
        sz[x] += sz[y];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dsu.merge(u, v);
    }
    vector<int> ve(n, MX);
    for (int i = 0; i < n; i++) {
        int par = dsu.fpar(i);
        ve[par] = min(ve[par], c[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (ve[i] != MX) {
            ans += ve[i];
        }
    }
    cout << ans << '\n';
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