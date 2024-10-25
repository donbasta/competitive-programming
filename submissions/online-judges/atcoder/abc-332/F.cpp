#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct Segtree {
    vector<ll> lmul, ladd;
    Segtree(int n) : lmul(4 * n + 5, 1), ladd(4 * n + 5, 0) {}
    void push(int v) {
        if (lmul[v] == 1 && ladd[v] == 0) return;
        lmul[v << 1] = lmul[v << 1] * lmul[v] % MOD;
        ladd[v << 1] = (ladd[v << 1] * lmul[v] + ladd[v]) % MOD;
        lmul[v << 1 | 1] = lmul[v << 1 | 1] * lmul[v] % MOD;
        ladd[v << 1 | 1] = (ladd[v << 1 | 1] * lmul[v] + ladd[v]) % MOD;
        lmul[v] = 1, ladd[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, ll mul, ll add) {
        if (s == l && e == r) {
            lmul[v] = lmul[v] * mul % MOD;
            ladd[v] = (ladd[v] * mul + add) % MOD;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, mul, add);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, mul, add);
        else {
            upd(v << 1, s, mid, l, mid, mul, add);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, mul, add);
        }
    }
    pair<ll, ll> que(int v, int s, int e, int idx) {
        if (s == e) {
            return make_pair(lmul[v], ladd[v]);
        }
        push(v);
        int mid = (s + e) >> 1;
        if (idx <= mid)
            return que(v << 1, s, mid, idx);
        else
            return que(v << 1 | 1, mid + 1, e, idx);
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    Segtree sgt(n);
    for (int i = 0; i < m; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        ll len = r - l + 1;
        ll inv_len = fpow(len, MOD - 2);
        ll mul = (len - 1) * inv_len % MOD;
        ll add = x * inv_len % MOD;
        sgt.upd(1, 0, n - 1, l, r, mul, add);
    }
    for (int i = 0; i < n; i++) {
        pair<ll, ll> x = sgt.que(1, 0, n - 1, i);
        ll ret = (x.first * ar[i] + x.second) % MOD;
        cout << ret << ' ';
    }
    cout << '\n';
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