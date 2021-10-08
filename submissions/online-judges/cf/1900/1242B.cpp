#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct dsu {
    int n;
    vector<int> par, sz;
    dsu(int _n) : n(_n) {
        par.resize(_n + 1);
        iota(par.begin(), par.end(), 0);
        sz.assign(_n + 1, 1);
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

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> from(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        from[b].emplace_back(a);
    }
    dsu ds = dsu(n);

    set<int> components;
    components.emplace(1);
    for (int i = 2; i <= n; i++) {
        map<int, int> tmp;
        for (auto e : from[i]) {
            tmp[ds.fpar(e)]++;
        }
        vector<int> ve;
        for (auto e : components) {
            if (tmp.find(e) == tmp.end()) {
                ds.merge(e, i);
                ve.emplace_back(e);
            } else if (tmp[e] < ds.sz[e]) {
                ds.merge(e, i);
                ve.emplace_back(e);
            }
        }
        for (auto e : ve) {
            components.erase(e);
        }
        components.emplace(ds.fpar(i));
    }
    int comp = (int) components.size();
    cout << comp - 1 << '\n';
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