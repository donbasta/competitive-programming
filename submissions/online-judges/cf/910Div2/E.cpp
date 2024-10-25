#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<int> tree;
    Segtree(int n) : tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    };
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<int> a, b;
    for (auto c : s) a.push_back(c - 'a');
    for (auto c : t) b.push_back(c - 'a');

    vector<vector<int>> posa(26), posb(26);
    for (int i = 0; i < n; i++) {
        posa[a[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        posb[b[i]].push_back(i);
    }

    for (int i = 0; i < 26; i++) {
        if (posa[i].size() < posb[i].size()) {
            cout << "NO" << '\n';
            return;
        }
    }

    Segtree sgt(m);
    sgt.build(1, 0, m - 1, b);

    vector<int> nx(26, 0);
    for (int i = 0; i < n; i++) {
        if (nx[a[i]] >= posb[a[i]].size()) continue;
        if (posb[a[i]][nx[a[i]]] >= 1) {
            int pref = sgt.get(1, 0, m - 1, 0, posb[a[i]][nx[a[i]]] - 1);
            if (pref > a[i]) {
                continue;
            }
        }
        sgt.upd(1, 0, m - 1, posb[a[i]][nx[a[i]]], -1);
        nx[a[i]]++;
    }

    for (int i = 0; i < 26; i++) {
        if (nx[i] < posb[i].size()) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}