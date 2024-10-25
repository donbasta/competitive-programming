#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct DSU {
    vector<unordered_map<int, ll>> ve;
    vector<int> par;
    DSU(int n) {
        ve.resize(n);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++) {
            ve[i][i] = 0;
        }
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    bool merge(int x, int y, ll sel) {
        int px = fpar(x), py = fpar(y);
        if (px == py) {
            return (ve[px][x] - ve[px][y] == sel);
        }
        if (ve[px].size() < ve[py].size()) {
            swap(x, y);
            swap(px, py);
            sel = -sel;
        }
        par[py] = px;
        for (auto e : ve[py]) {
            ve[px][e.first] = (e.second - ve[py][y]) + (ve[px][x] - sel);
        }
        return true;
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<int> ret;
    DSU dsu(n);
    for (int i = 1; i <= q; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        --a, --b;
        if (dsu.merge(a, b, d)) {
            ret.push_back(i);
        }
    }
    for (auto e : ret) {
        cout << e << ' ';
    }
    cout << '\n';
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