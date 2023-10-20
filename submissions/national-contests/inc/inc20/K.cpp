#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = (tree[v << 1] + tree[v << 1 | 1]) % MOD;
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return (get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r)) % MOD;
    }
    void upd(int idx, int val) {
        upd(1, 0, n - 1, idx, val);
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    vector<pair<int, int>> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ve[i].first = ar[i];
        ve[i].second = i;
    }
    sort(ve.begin(), ve.end());
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[ve[i].second] = i;
    }
    vector<int> dp(n);
    Segtree sgt1(n), sgt2(n);
    sgt1.upd(pos[0], 1);
    sgt2.upd(pos[0], ar[0]);
    for (int i = 1; i < n; i++) {
        int A1 = sgt1.get(0, pos[i] - 1);
        int A2 = sgt2.get(0, pos[i] - 1);
        int B1 = sgt1.get(pos[i] + 1, n - 1);
        int B2 = sgt2.get(pos[i] + 1, n - 1);
        int tmp = 0;
        tmp = (1ll * tmp + 1ll * ar[i] * A1) % MOD;
        tmp = (1ll * tmp - 1ll * A2) % MOD;
        tmp = (1ll * tmp - 1ll * ar[i] * B1) % MOD;
        tmp = (1ll * tmp + 1ll * B2) % MOD;
        if (tmp < 0) tmp += MOD;
        dp[i] = tmp;

        sgt1.upd(pos[i], (tmp + 1) % MOD);
        sgt2.upd(pos[i], (1ll * ar[i] * (tmp + 1)) % MOD);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}