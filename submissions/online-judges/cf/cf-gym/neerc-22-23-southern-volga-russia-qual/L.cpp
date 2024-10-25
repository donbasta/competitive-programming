#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 3e5;
const int MOD = 998244353;

struct Segtree {
    vector<int> tree, lz;
    // int tree[4 * M + 10], lz[4 * M + 10];
    Segtree() {
        tree.resize(4 * M + 10);
        lz.resize(4 * M + 10);
        // memset(tree, 0, sizeof(tree));
        // memset(lz, 0, sizeof(lz));
    }
    void push(int v) {
        if (lz[v] == 0) return;
        tree[v << 1] = tree[v << 1 | 1] = lz[v];
        lz[v << 1] = lz[v << 1 | 1] = lz[v];
        lz[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            tree[v] = val;
            lz[v] = val;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
    }
    int get(int v, int s, int e, int idx) {
        if (s == e) {
            return tree[v];
        }
        push(v);
        int mid = (s + e) >> 1;
        if (idx <= mid) return get(v << 1, s, mid, idx);
        return get(v << 1 | 1, mid + 1, e, idx);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;

    Segtree sgt;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        sgt.upd(1, 0, M, l, r, i);
    }
    vector<int> pw2(n + 1), pw3(n + 1);
    pw2[0] = pw3[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw2[i] = (1ll * pw2[i - 1] * 2) % MOD;
        pw3[i] = (1ll * pw3[i - 1] * 3) % MOD;
    }

    int ans = 0;
    for (int i = 0; i <= M; i++) {
        int la = sgt.get(1, 0, M, i);
        if (la == 0) continue;
        int pw = pw2[n - 1];
        if (la > 1) {
            pw = (1ll * pw3[la - 2] * pw2[n + 1 - la]) % MOD;
        }
        ans = (1ll * ans + pw) % MOD;
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