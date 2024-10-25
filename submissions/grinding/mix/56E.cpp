#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    int n;
    vector<ll> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else if (idx >= mid)
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int idx, ll val) {
        upd(1, 0, n - 1, idx, val);
    }
    ll get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ve;
    for (int i = 0; i < n; i++) {
        ll x, h;
        cin >> x >> h;
        ve.emplace_back(x, h);
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
        return ve[a] < ve[b];
    });
    sort(ve.begin(), ve.end());
    vector<ll> bases(n);
    for (int i = 0; i < n; i++) {
        bases[i] = ve[i].first;
    }
    Segtree sgt(n);
    vector<ll> rightmost(n);
    for (int i = n - 1; i >= 0; i--) {
        ll l = ve[i].first + 1;
        ll r = ve[i].first + ve[i].second - 1;
        ll bl = lower_bound(bases.begin(), bases.end(), l) - bases.begin();
        ll br = upper_bound(bases.begin(), bases.end(), r) - bases.begin();
        br--;
        if (bl > br) {
            rightmost[i] = r;
        } else {
            rightmost[i] = sgt.get(bl, br);
        }
        sgt.upd(i, rightmost[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ll l = bases[i], r = rightmost[i];
        ll br = upper_bound(bases.begin(), bases.end(), r) - bases.begin();
        ans[idx[i]] = (br - i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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