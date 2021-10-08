#include <bits/stdc++.h>

using namespace std;

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
