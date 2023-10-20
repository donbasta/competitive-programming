#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        --b[i];
    }
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) continue;
        ve.emplace_back(b[i], a[i]);
    }
    if (ve.empty()) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    sort(ve.begin(), ve.end());
    int sz = ve.size();
    vector<int> ar(sz);
    for (int i = 0; i < sz; i++) {
        ar[i] = ve[i].second;
    }
    Segtree sgt(sz);
    sgt.build(1, 0, sz - 1, ar);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j += i) {
            // interval [j, j + i - 1];
            int a = lower_bound(ve.begin(), ve.end(), make_pair(j, -1)) - ve.begin();
            int b = lower_bound(ve.begin(), ve.end(), make_pair(j + i, -1)) - ve.begin();
            if (a > b - 1) continue;
            if (sgt.get(1, 0, sz - 1, a, b - 1) >= j + i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
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