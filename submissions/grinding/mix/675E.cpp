#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

struct Segtree {
    vector<ll> tree;
    Segtree(int n) : tree(4 * n + 5, INF) {}
    void upd(int v, int s, int e, int idx, ll val) {
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
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return min(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> ar[i];
        ar[i]--;
    }
    ll ans = 0;
    Segtree sgt(n);
    vector<ll> F(n);
    sgt.upd(1, 0, n - 1, n - 1, n - 1);
    for (int i = n - 2; i >= 0; i--) {
        ll T = sgt.get(1, 0, n - 1, i + 1, ar[i]);
        F[i] = n - 1 - i + T - ar[i];
        ans += F[i];
        sgt.upd(1, 0, n - 1, i, F[i] + i);
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