#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<int> tree, eq;
    vector<bool> flip;
    Segtree(int n) {
        tree.resize(4 * n + 5);
        eq.assign(4 * n + 5, -1);
        flip.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void push(int v, int s, int e) {
        int mid = (s + e) >> 1;
        if (eq[v] != -1) {
            eq[v << 1] = eq[v << 1 | 1] = eq[v];
            flip[v << 1] = flip[v << 1 | 1] = false;
            tree[v << 1] = ((eq[v] == 1) ? (mid - s + 1) : 0);
            tree[v << 1 | 1] = ((eq[v] == 1) ? (e - mid) : 0);
            eq[v] = -1;
        }
        if (flip[v]) {
            flip[v << 1] = !flip[v << 1];
            flip[v << 1 | 1] = !flip[v << 1 | 1];
            tree[v << 1] = (mid - s + 1) - tree[v << 1];
            tree[v << 1 | 1] = (e - mid) - tree[v << 1 | 1];
            flip[v] = false;
        }
    }
    void upd_set(int v, int s, int e, int l, int r, int new_val) {
        if (s == l && e == r) {
            eq[v] = new_val;
            tree[v] = (new_val == 1 ? (r - l + 1) : 0);
            flip[v] = false;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd_set(v << 1, s, mid, l, r, new_val);
        } else if (l >= mid + 1) {
            upd_set(v << 1 | 1, mid + 1, e, l, r, new_val);
        } else {
            upd_set(v << 1, s, mid, l, mid, new_val);
            upd_set(v << 1 | 1, mid + 1, e, mid + 1, r, new_val);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void upd_flip(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            flip[v] = !flip[v];
            tree[v] = (r - l + 1) - tree[v];
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd_flip(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            upd_flip(v << 1 | 1, mid + 1, e, l, r);
        } else {
            upd_flip(v << 1, s, mid, l, mid);
            upd_flip(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return get(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return get(v << 1 | 1, mid + 1, e, l, r);
        }
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    Segtree sgt(n);
    sgt.build(1, 0, n - 1, ar);
    for (int i = 0; i < m; i++) {
        string tp;
        int x, y;
        cin >> tp >> x >> y;
        --x, --y;
        if (tp == "flip") {
            sgt.upd_flip(1, 0, n - 1, x, y);
        } else if (tp == "sort") {
            int cnt = sgt.get(1, 0, n - 1, x, y);
            if (y - cnt >= x) {
                sgt.upd_set(1, 0, n - 1, x, y - cnt, 0);
            }
            if (cnt >= 1) {
                sgt.upd_set(1, 0, n - 1, y - cnt + 1, y, 1);
            }
        }
    }
    int cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = sgt.get(1, 0, n - 1, i, i);
        if (tmp == 0) {
            ans += cnt;
        } else if (tmp == 1) {
            cnt++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}