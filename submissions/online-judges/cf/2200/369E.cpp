#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<vector<int>> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = {ar[s]};
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
    }
    int get(int v, int s, int e, int l, int r, int c) {  // <= c
        if (r < l) return 0;
        if (s == l && e == r) {
            return upper_bound(tree[v].begin(), tree[v].end(), c) - tree[v].begin();
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r, c);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r, c);
        return get(v << 1, s, mid, l, mid, c) + get(v << 1 | 1, mid + 1, e, mid + 1, r, c);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ve.emplace_back(l, r);
    }
    sort(ve.begin(), ve.end());
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        L[i] = ve[i].first, R[i] = ve[i].second;
    }
    Segtree sgt(n);
    sgt.build(1, 0, n - 1, R);
    const int MX = 1e6;
    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        vector<int> P(cnt);
        vector<int> pos1(cnt), pos2(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> P[j];
            pos1[j] = upper_bound(L.begin(), L.end(), P[j]) - L.begin();
            pos2[j] = lower_bound(L.begin(), L.end(), P[j]) - L.begin();
        }
        int ans = 0;
        ans += sgt.get(1, 0, n - 1, 0, pos2[0] - 1, P[0] - 1);
        for (int j = 0; j < cnt - 1; j++) {
            ans += sgt.get(1, 0, n - 1, pos1[j], pos2[j + 1] - 1, P[j] - 1);
        }
        ans += sgt.get(1, 0, n - 1, pos1[cnt - 1], n - 1, MX);
        cout << n - ans << '\n';
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