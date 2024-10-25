#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<int> tree;
    vector<bool> lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void push(int v, int s, int e) {
        if (!lz[v]) return;
        int mid = (s + e) >> 1;
        tree[v << 1] = mid - s + 1;
        tree[v << 1 | 1] = e - mid;
        lz[v << 1] = lz[v << 1 | 1] = true;
        lz[v] = false;
    }
    void upd(int v, int s, int e, int l, int r) {  // update to 1
        if (s == l && e == r) {
            tree[v] = (e - s + 1);
            lz[v] = true;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            upd(v << 1 | 1, mid + 1, e, l, r);
        } else {
            upd(v << 1, s, mid, l, mid);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> itv;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        itv.emplace_back(l, r);
    }

    int ans = 0;
    Segtree sgt(n);

    vector<bool> used(m);
    for (int j = 0; j < m; j++) {
        int mn = INT_MAX;
        int idx = -1;
        for (int k = 0; k < m; k++) {
            if (used[k]) continue;
            int l = itv[k].first;
            int r = itv[k].second;
            int off = ((r - l + 1) - sgt.get(1, 0, n - 1, l, r));
            if (off < mn) {
                mn = off;
                idx = k;
            }
        }
        assert(idx != -1);
        if (mn > 0) {
            int l = itv[idx].first;
            int r = itv[idx].second;
            sgt.upd(1, 0, n - 1, l, r);
            ans++;
        }
        cerr << itv[idx].first << ' ' << itv[idx].second << '\n';
        used[idx] = true;
    }

    cout << ans << '\n';
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