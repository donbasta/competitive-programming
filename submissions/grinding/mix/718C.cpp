#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using mat = array<array<ll, 2>, 2>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const mat ID = {{{1, 0}, {0, 1}}};
const mat FIBO = {{{1, 1}, {1, 0}}};

pair<ll, ll> add(pair<ll, ll> a, pair<ll, ll> b) {
    return make_pair((a.first + b.first) % MOD, (a.second + b.second) % MOD);
}

mat mul(const mat& A, const mat& B) {
    mat ret;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ret[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ret;
}

mat fpow(mat A, ll b) {
    mat ret = ID;
    while (b) {
        if (b & 1) ret = mul(ret, A);
        A = mul(A, A);
        b >>= 1;
    }
    return ret;
}

pair<ll, ll> mul(pair<ll, ll> a, const mat& B) {
    ll x = (a.first * B[0][0] + a.second * B[1][0]) % MOD;
    ll y = (a.first * B[0][1] + a.second * B[1][1]) % MOD;
    return make_pair(x, y);
}

ll fibo(ll idx) {
    if (idx == 0) return 0;
    mat fp = fpow(FIBO, idx - 1);
    return fp[0][0];
}

struct Segtree {
    vector<pair<int, int>> tree;
    vector<mat> lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5, ID) {}
    void build(int v, int s, int e, const vector<pair<int, int>>& T) {
        if (s == e) {
            tree[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = add(tree[v << 1], tree[v << 1 | 1]);
    }
    void push(int v, int s, int e) {
        if (lz[v] == ID) return;
        lz[v << 1] = mul(lz[v << 1], lz[v]);
        lz[v << 1 | 1] = mul(lz[v << 1 | 1], lz[v]);
        tree[v << 1] = mul(tree[v << 1], lz[v]);
        tree[v << 1 | 1] = mul(tree[v << 1 | 1], lz[v]);
        lz[v] = ID;
    }
    void upd(int v, int s, int e, int l, int r, const mat& K) {
        if (s == l && e == r) {
            tree[v] = mul(tree[v], K);
            lz[v] = mul(lz[v], K);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, K);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, K);
        else {
            upd(v << 1, s, mid, l, mid, K);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, K);
        }
        tree[v] = add(tree[v << 1], tree[v << 1 | 1]);
    }
    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return add(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ve.emplace_back(fibo(a), fibo(a - 1));
    }
    Segtree sgt(n);
    sgt.build(1, 0, n - 1, ve);
    for (int i = 0; i < m; i++) {
        int tp, l, r, x;
        cin >> tp >> l >> r;
        --l, --r;
        if (tp == 1) {
            cin >> x;
            mat fx = fpow(FIBO, x);
            sgt.upd(1, 0, n - 1, l, r, fx);
        } else if (tp == 2) {
            cout << sgt.get(1, 0, n - 1, l, r).first << '\n';
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