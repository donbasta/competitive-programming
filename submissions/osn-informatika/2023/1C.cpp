#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

struct DSU {
    vector<int> par;
    vector<unordered_map<int, ll>> group;
    DSU(int n) {
        par.assign(n, -1);
        group.resize(n);
    }
    void init(int x, ll val_x) {
        par[x] = x;
        group[x][x] = val_x;
    }
    int fpar(int x) {
        return (x == par[x] ? x : par[x] = fpar(par[x]));
    }
    bool merge(int x, int y, ll val_x, ll val_y) {
        int px = fpar(x), py = fpar(y);
        if (px == py) {
            if (val_y - val_x == group[px][y] - group[px][x]) {
                return true;
            } else {
                return false;
            }
        }
        if (group[px].size() < group[py].size()) {
            swap(x, y);
            swap(px, py);
            swap(val_x, val_y);
        }
        par[py] = px;
        ll sel = (group[px][x] + val_y - val_x) - (group[py][y]);
        for (auto c : group[py]) {
            if (group[px].find(c.first) != group[px].end()) {
                if (c.second + sel != group[px][c.first]) {
                    return false;
                }
            } else {
                group[px][c.first] = c.second + (sel);
            }
        }
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    ll ve[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ve[i][j];
        }
    }
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        vector<pair<int, ll>> tmp;
        for (int j = 0; j < n; j++) {
            if (ve[i][j] != -1) {
                tmp.emplace_back(j, ve[i][j]);
            }
        }
        int sz = tmp.size();
        if (sz == 0) continue;
        for (int j = 0; j < sz; j++) {
            if (dsu.par[tmp[j].first] == -1) {
                dsu.init(tmp[j].first, tmp[j].second);
            }
        }
        int a = tmp[0].first;
        ll val_a = tmp[0].second;
        for (int j = 1; j < sz; j++) {
            bool consistent = dsu.merge(tmp[j].first, a, tmp[j].second, val_a);
            if (!consistent) {
                cout << 0 << '\n';
                return;
            }
        }
    }
    ll mn[n];
    for (int i = 0; i < n; i++) mn[i] = INF;
    for (int i = 0; i < n; i++) {
        int pivot = -1;
        for (int j = 0; j < n; j++) {
            if (ve[i][j] != -1) {
                pivot = j;
                break;
            }
        }
        if (pivot == -1) continue;
        int par = dsu.fpar(pivot);
        ll x = dsu.group[par][pivot], y = ve[i][pivot];
        for (auto c : dsu.group[par]) {
            if (ve[i][c.first] != -1) {
                assert(ve[i][c.first] == c.second + y - x);
            }
            mn[par] = min(mn[par], c.second + y - x);
        }
    }
    for (int i = 0; i < n; i++) {
        if (mn[i] < 0) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        int c1 = 0, c2 = 0;
        for (int j = 0; j < n; j++) {
            c1 += ve[i][j] != -1;
            c2 += ve[j][i] != -1;
        }
        if (c1 == 0 || c2 == 0) {
            cout << -1 << '\n';
            return;
        }
    }
    const ll MOD = 1e9 + 7;
    ll A = 1, B = 1;
    for (int i = 0; i < n; i++) {
        if (mn[i] == INF) continue;
        A = (A * (mn[i] + 1)) % MOD;
        B = (B * mn[i]) % MOD;
    }
    ll ans = (A - B) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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