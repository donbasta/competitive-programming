#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 30;

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) : n(_n) {
        par.resize(_n);
        iota(par.begin(), par.end(), 0);
        sz.assign(_n, 1);
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

void solve () {
    int n;
    cin >> n;
    vector<int> ve(n);
    vector<ll> val(n);
    vector<vector<int>> ar(MX);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        int fr;
        for (int j = 0; j < MX; j++) {
            if (ve[i] & (1 << j)) {
                fr = j;
            }
        }
        for (int j = 0; j < fr; j++) {
            if (!(ve[i] & (1 << j))) {
                ar[j].emplace_back(i);
            }
        }
        ar[fr].emplace_back(i + n);
    }
    vector<int> par2(n);
    DSU dsu2(n);
    for (int i = 0; i < MX; i++) {
        if (ar[i].empty()) continue;
        sort(ar[i].begin(), ar[i].end());
        bool ok = (ar[i][0] < n && ar[i].back() >= n);
        if (ok) {
            int x = ar[i][0];
            for (auto j : ar[i]) {
                if (j >= n) {
                    j -= n;
                }
                dsu2.merge(x, j);
            }
        }
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        par2[i] = dsu2.fpar(i);
        ans[par2[i]] += val[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[par2[i]] << "\n";
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}