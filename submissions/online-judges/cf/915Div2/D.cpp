#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<ll> tree;
    vector<bool> lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void build(int v, int s, int e, const vector<ll>& T) {
        if (s == e) {
            tree[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void push(int v, int s, int e) {
        if (!lz[v]) return;
        lz[v << 1] = lz[v << 1 | 1] = true;
        tree[v << 1] = tree[v << 1 | 1] = 0;
        lz[v] = false;
    }
    void upd_zero(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            tree[v] = 0;
            lz[v] = true;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd_zero(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            upd_zero(v << 1 | 1, mid + 1, e, l, r);
        else {
            upd_zero(v << 1, s, mid, l, mid);
            upd_zero(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return (
            get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<bool> tmp(n + 1);
    vector<ll> mex(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        tmp[p[i]] = true;
        while (tmp[cur]) cur++;
        mex[i] = cur;
    }
    ll csum = accumulate(mex.begin(), mex.end(), 0ll);
    // cerr << csum << '\n';
    ll ans = csum;
    Segtree sgt_sum(n + 1), sgt_count(n + 1);

    vector<ll> cnt(n + 1), sm(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[mex[i]]++;
    }
    for (int i = 0; i <= n; i++) {
        sm[i] = cnt[i] * i;
    }
    sgt_count.build(1, 0, n, cnt);
    sgt_sum.build(1, 0, n, sm);
    for (int i = 1; i < n; i++) {
        ll A = sgt_sum.get(1, 0, n, p[i - 1] + 1, n);
        ll B = sgt_count.get(1, 0, n, p[i - 1] + 1, n);
        // cerr << A << ' ' << B << '\n';
        csum = csum - A + 1ll * p[i - 1] * B + n;
        ans = max(ans, csum);
        ll cur_sum = sgt_sum.get(1, 0, n, p[i - 1], p[i - 1]);
        ll cur_count = sgt_count.get(1, 0, n, p[i - 1], p[i - 1]);
        sgt_sum.upd(1, 0, n, p[i - 1], cur_sum + 1ll * p[i - 1] * B);
        sgt_count.upd(1, 0, n, p[i - 1], cur_count + B);
        sgt_sum.upd_zero(1, 0, n, p[i - 1] + 1, n);
        sgt_count.upd_zero(1, 0, n, p[i - 1] + 1, n);
        sgt_sum.upd(1, 0, n, n, n);
        sgt_count.upd(1, 0, n, n, 1);
        // cerr << i << ' ' << csum << '\n';
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
        el_psy_congroo();
    }

    return 0;
}