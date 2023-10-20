#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 1e9 + 7;

struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : tree(4 * n + 5), n(n) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else if (idx >= mid + 1)
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
    int n, k;
    cin >> n >> k;
    vector<int> ar(n), le(n, -1), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pre[i] = (ar[i] == 1) + (i ? pre[i - 1] : 0);
    }
    Segtree sgt(n);
    for (int i = 0; i < n; i++) {
        if (ar[i] == 1)
            le[i] = i;
        else if (i > 0)
            le[i] = le[i - 1];
    }
    auto cnt = [&](int l, int r) -> int {
        return pre[r] - (l ? pre[l - 1] : 0);
    };
    // for (int i = 0; i < n; i++) {
    //     cerr << i << ' ' << pre[i] << ' ' << le[i] << '\n';
    // }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int R = le[i];
        int L = le[i];
        if (R == -1) continue;
        if (R == 0) {
            dp[i] = 1;
            sgt.upd(i, dp[i]);
            continue;
        }

        int l = 0, r = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (cnt(mid, i) > k) {
                l = mid + 1;
            } else {
                L = mid;
                r = mid - 1;
            }
        }
        // dp[i] = dp[R - 1] + dp[R - 2] + ... + dp[L]
        dp[i] = sgt.get(L, R - 1);
        if (L == 0)
            dp[i] = (dp[i] + 1) % MOD;
        else
            dp[i] = (dp[i] + dp[L - 1]) % MOD;
        sgt.upd(i, dp[i]);
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}