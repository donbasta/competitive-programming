#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<int> tree, lz;
    Segtree(int n) {
        tree.resize(4 * n + 5);
        lz.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    void push(int v, int s, int e) {
        if (lz[v] == 0) return;
        tree[v << 1] = tree[v << 1 | 1] = tree[v];
        lz[v << 1] = lz[v << 1 | 1] = lz[v];
        lz[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            tree[v] = val;
            lz[v] = val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);

        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    set<pair<int, int>> se;
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            se.emplace(l, i - 1);
            l = i;
        }
    }
    se.emplace(l, n - 1);
    vector<int> len(n);
    for (auto e : se) {
        for (int i = e.first; i <= e.second; i++) {
            len[i] = e.second - e.first + 1;
        }
    }

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, len);

    auto find_ptr_containing = [&](int p) {
        auto up = se.upper_bound(make_pair(p, INF));
        --up;
        return up;
    };

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            // auto x = find_ptr_containing(l);
            // auto y = find_ptr_containing(r);
            // if (x == y) {
            //     if (l == x->first && r == x->second) {
            //         int L = l, R = r;
            //         auto tmp = x;
            //         if (tmp != se.begin()) {
            //             L = (--tmp)->first;
            //         }
            //         tmp = x;
            //         ++tmp;
            //         if (tmp != se.end()) {
            //             R = tmp->second;
            //         }
            //         sgt.upd(1, 0, n - 1, L, R, R - L + 1);
            //     } else if (l == x->first) {
            //         int L = l, R = r;
            //         auto tmp = x;
            //         if (tmp != se.begin()) {
            //             L = (--tmp)->first;
            //         }
            //         sgt.upd(1, 0, n - 1, L, R, R - L + 1);
            //     } else if (r == x->second) {
            //         int L = l, R = r;
            //         auto tmp = x;
            //         ++tmp;
            //         if (tmp != se.end()) {
            //             R = tmp->second;
            //         }
            //         sgt.upd(1, 0, n - 1, L, R, R - L + 1);
            //     } else {
            //         sgt.upd(1, 0, n - 1, x->first, l - 1, l - 1 - x->first + 1);
            //         sgt.upd(1, 0, n - 1, l, r, r - l + 1);
            //         sgt.upd(1, 0, n - 1, r + 1, x->second, x->second - (r + 1) + 1);
            //     }
            // } else {
            //     if (l == x->first) {
            //         auto tmp = x;
            //         int L = l;
            //         if (tmp != se.begin()) {
            //             L = (--tmp)->first;
            //         }
            //         sgt.upd(1, 0, n - 1, L, x->second, x->second - L + 1);
            //     } else {
            //         sgt.upd(1, 0, n - 1, x->first, l - 1, l - 1 - x->first + 1);
            //         sgt.upd(1, 0, n - 1, l, x->second, x->second - l + 1);
            //     }
            //     if (r == y->second) {
            //         auto tmp = y;
            //         tmp++;
            //         int R = r;
            //         if (tmp != se.end()) {
            //             R = tmp->second;
            //         }
            //         sgt.upd(1, 0, n - 1, y->first, R, R - y->first + 1);
            //     } else {
            //         sgt.upd(1, 0, n - 1, y->first, r - 1, r - 1 - y->first + 1);
            //         sgt.upd(1, 0, n - 1, r, y->second, y->second - r + 1);
            //     }
            // }
        } else {
            cout << sgt.get(1, 0, n - 1, l, r) << '\n';
        }
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