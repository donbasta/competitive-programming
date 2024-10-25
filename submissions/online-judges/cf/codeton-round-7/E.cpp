#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx) {
        if (s == e) {
            tree[idx] = 1;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx);
        else if (idx >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, idx);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    void upd(int idx) {
        upd(1, 0, n - 1, idx);
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ar[i]--;
        pos[ar[i]] = i;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        to[i] = i;
        if (to[i] < pos[i]) to[i] += n;
    }
    sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
        return to[a] - a < to[b] - b;
    });
    Segtree sgt(n);
    int cur = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int cnt;
        if (idx[i] >= pos[idx[i]]) {
            cnt = sgt.get(pos[idx[i]], idx[i]);
        } else {
            cnt = sgt.get(pos[idx[i]], n - 1) + sgt.get(0, idx[i]);
        }
        cerr << idx[i] << ' ' << cnt << '\n';
        ans[idx[i]] = to[idx[i]] - idx[i] - cnt;
        sgt.upd(idx[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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