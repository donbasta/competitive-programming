#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int D = 20;
const int MOD = 1e9 + 7;
const int M = 1e5;

int pw2[M + 5];

void init() {
    pw2[0] = 1;
    for (int i = 1; i <= M; i++) {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    }
}

struct node {
    vector<int> basis;
    int sz;
    node() {
        basis.resize(D + 1);
        sz = 0;
    }
    void add(int x) {
        for (int i = 0; i <= D; i++) {
            if (!((x >> i) & 1)) continue;
            if (!basis[i]) {
                basis[i] = x;
                ++sz;
                return;
            }
            x ^= basis[i];
        }
    }
};

node merge(node a, node b) {
    node ret = a;
    for (int i = 0; i <= D; i++) {
        ret.add(b.basis[i]);
    }
    return ret;
}

struct Segtree {
    vector<node> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v].add(ar[s]);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
    node get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return get(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return get(v << 1 | 1, mid + 1, e, l, r);
        }
        return merge(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, ve);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int le = i;
        for (int j = 0; j <= D; j++) {
            int l = le, r = n - 1;
            int pt = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                node bas = sgt.get(1, 0, n - 1, i, mid);
                if (bas.sz > j) {
                    r = mid - 1;
                } else {
                    pt = mid;
                    l = mid + 1;
                }
            }
            if (pt == -1)
                continue;
            else {
                ans = (1ll * ans + 1ll * (pt - le + 1) * pw2[j]) % MOD;
                le = pt + 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}