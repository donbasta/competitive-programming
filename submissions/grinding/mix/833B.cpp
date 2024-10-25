#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

struct Segtree {
    vector<vector<int>> tree;
    Segtree(int n) : tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<int>& T) {
        if (s == e) {
            tree[v] = vector<int>{T[s]};
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
    }
    int get(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            return tree[v].size() - (upper_bound(tree[v].begin(), tree[v].end(), val) - tree[v].begin());
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r, val);
        return get(v << 1, s, mid, l, mid, val) + get(v << 1 | 1, mid + 1, e, mid + 1, r, val);
    }
};

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    Segtree sgt(n);
    vector<int> nx(n, n);
    map<int, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(ar[i])) nx[i] = mp[ar[i]];
        mp[ar[i]] = i;
    }
    sgt.build(1, 0, n - 1, nx);
    vector<ll> dp(n), ndp(n);

    function<void(int, int, int, int)> compute = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        pair<ll, int> best = make_pair(-INF, -1);
        int cost = sgt.get(1, 0, n - 1, optl, mid, mid);
        for (int i = optl; i <= min(optr, mid); i++) {
            best = max(best, make_pair((i ? dp[i - 1] : 0) + cost, i));
            if (nx[i] > mid) cost--;
        }
        ndp[mid] = best.first;
        int opt = best.second;
        compute(l, mid - 1, optl, opt);
        compute(mid + 1, r, opt, optr);
    };

    for (int i = 0; i < n; i++) {
        dp[i] = sgt.get(1, 0, n - 1, 0, i, i);
    }
    for (int i = 1; i < k; i++) {
        compute(0, n - 1, 0, n - 1);
        dp = ndp;
    }
    cout << dp[n - 1] << '\n';
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