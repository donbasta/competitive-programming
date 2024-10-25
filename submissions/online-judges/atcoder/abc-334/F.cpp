#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld INF = 1e30;

struct Segtree {
    vector<ld> tree;
    Segtree(int n) : tree(4 * n + 5, INF) {}
    void upd(int v, int s, int e, int idx, ld val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    ld get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return min(
            get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

ld dist(ll x1, ll y1, ll x2, ll y2) {
    return hypot(x1 - x2, y1 - y2);
}

void el_psy_congroo() {
    cerr << fixed << setprecision(15);

    int n, k;
    cin >> n >> k;
    ll sx, sy;
    cin >> sx >> sy;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<ld> st(n);
    for (int i = 0; i < n; i++) {
        st[i] = dist(sx, sy, x[i], y[i]);
    }
    ld base = dist(sx, sy, x[0], y[0]);
    for (int i = 1; i < n; i++) {
        base += dist(x[i - 1], y[i - 1], x[i], y[i]);
    }
    base += dist(x[n - 1], y[n - 1], sx, sy);
    vector<ld> P(n);
    for (int i = 0; i < n - 1; i++) {
        P[i] = st[i] + st[i + 1] - dist(x[i], y[i], x[i + 1], y[i + 1]);
    }
    Segtree sgt(n);
    vector<ld> dp(n);
    // dp[i] = min(dp[i - 1], ..., dp[i - k]) + P[i]
    for (int i = 0; i < n - 1; i++) {
        ld prv;
        if (i - k < 0)
            prv = 0;
        else {
            prv = sgt.get(1, 0, n - 1, i - k, i - 1);
        }
        dp[i] = prv + P[i];
        sgt.upd(1, 0, n - 1, i, dp[i]);
    }
    ld tam = INF;
    for (int i = n - k - 1; i < n - 1; i++) {
        if (i < 0) tam = 0;
        tam = min(tam, dp[i]);
    }
    base += tam;
    cout << fixed << setprecision(15) << base << '\n';
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