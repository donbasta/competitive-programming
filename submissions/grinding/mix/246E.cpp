#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<vector<int>> tree;
    int n;
    Segtree() {}
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = vector<int>{T[s]};
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
    }
    int get(int v, int s, int e, int l, int r, int bat) {
        if (s == l && e == r) {
            return (int)tree[v].size() - (upper_bound(tree[v].begin(), tree[v].end(), bat) - tree[v].begin());
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r, bat);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r, bat);
        return get(v << 1, s, mid, l, mid, bat) + get(v << 1 | 1, mid + 1, e, mid + 1, r, bat);
    }
    int get(int l, int r, int bat) {
        if (l > r) return 0;
        return get(1, 0, n - 1, l, r, bat);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> par(n);
    // int root = -1;
    vector<vector<int>> chd(n);
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> par[i];
        if (par[i] == 0)
            roots.push_back(i);
        else {
            par[i]--;
            chd[par[i]].push_back(i);
        }
    }
    vector<int> dep(n), tin(n), sz(n);
    vector<vector<int>> v1(n);
    vector<vector<string>> v2(n);
    // vector<vector<pair<int, string>>> ve(n);
    int T = 0;
    const function<void(int)> dfs = [&](int v) {
        tin[v] = T++;
        // ve[dep[v]].emplace_back(tin[v], names[v]);
        v1[dep[v]].push_back(tin[v]);
        v2[dep[v]].push_back(names[v]);
        sz[v] = 1;
        for (auto c : chd[v]) {
            dep[c] = dep[v] + 1;
            dfs(c);
            sz[v] += sz[c];
        }
    };
    for (auto r : roots) {
        dfs(r);
    }
    // dfs(root);
    vector<Segtree> lmao(n);
    for (int i = 0; i < n; i++) {
        int sz = v1[i].size();
        if (sz == 0) continue;
        vector<int> nx(sz, sz);
        map<string, int> lst;
        for (int j = sz - 1; j >= 0; j--) {
            if (lst.count(v2[i][j])) {
                nx[j] = lst[v2[i][j]];
            }
            lst[v2[i][j]] = j;
        }
        Segtree sgt(sz);
        sgt.build(1, 0, sz - 1, nx);
        lmao[i] = sgt;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        --v;
        int idx = dep[v] + k;
        if (idx >= n || v1[idx].empty()) {
            cout << 0 << '\n';
            continue;
        }
        int l = lower_bound(v1[idx].begin(), v1[idx].end(), tin[v]) - v1[idx].begin();
        int r = lower_bound(v1[idx].begin(), v1[idx].end(), tin[v] + sz[v]) - v1[idx].begin();
        --r;
        cout << lmao[idx].get(l, r, r) << '\n';
    }
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