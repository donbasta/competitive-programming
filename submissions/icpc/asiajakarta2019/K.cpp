#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 1e9 + 7;

using mat = vector<vector<ll>>;

const mat B = {{1, 1}, {0, 1}};
const mat A = {{1, 0}, {1, 1}};

mat mul(mat x, mat y) {
    mat res(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] + x[i][k] * y[k][j]) % MOD;
            }
        }
    }
    return res;
}

void modify(mat& x) {
    swap(x[0][0], x[1][1]);
    swap(x[0][1], x[1][0]);
}

struct Segtree {
    vector<mat> tree;
    vector<bool> lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void build(int v, int s, int e, const string& S) {
        if (s == e) {
            if (S[s] == 'A')
                tree[v] = A;
            else
                tree[v] = B;
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, S);
        build(v << 1 | 1, mid + 1, e, S);
        tree[v] = mul(tree[v << 1], tree[v << 1 | 1]);
    }
    void push(int v) {
        if (!lz[v]) return;
        lz[v << 1] = lz[v << 1] ^ 1;
        lz[v << 1 | 1] = lz[v << 1 | 1] ^ 1;
        modify(tree[v << 1]);
        modify(tree[v << 1 | 1]);
        lz[v] = false;
    }
    void upd(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            modify(tree[v]);
            lz[v] = lz[v] ^ 1;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r);
        else {
            upd(v << 1, s, mid, l, mid);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = mul(tree[v << 1], tree[v << 1 | 1]);
    }
    mat get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return mul(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    Segtree sgt(n);
    sgt.build(1, 0, n - 1, s);
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            sgt.upd(1, 0, n - 1, l, r);
        } else if (tp == 2) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            --l, --r;
            mat M = sgt.get(1, 0, n - 1, l, r);
            ll aa = (1ll * M[0][0] * a + 1ll * M[1][0] * b) % MOD;
            ll bb = (1ll * M[0][1] * a + 1ll * M[1][1] * b) % MOD;
            cout << aa << ' ' << bb << '\n';
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