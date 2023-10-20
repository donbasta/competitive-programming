#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<int> tree;
    Segtree(int n) {
        tree.assign(4 * n + 5, -INF);
    }
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
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int que(int v, int s, int e, int l, int r) {
        if (r < l) return -INF;
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return que(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return que(v << 1 | 1, mid + 1, e, l, r);
        return max(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int par;
        cin >> par;
        --par;
        adj[par].push_back(i + 1);
    }
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        ve.emplace_back(val[i], i);
    }
    sort(ve.begin(), ve.end());
    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[ve[i].second] = i;
    }
    Segtree sgt(n);
    vector<int> dp(n), ddp(n);
    const function<void(int)> dfs = [&](int v) {
        for (auto c : adj[v]) {
            dp[c] = 1;
            int x = lower_bound(ve.begin(), ve.end(), make_pair(val[c], -1)) - ve.begin();
            if (x > 0) {
                dp[c] = max(dp[c], 1 + sgt.que(1, 0, n - 1, 0, x - 1));
            }
            ddp[c] = max(ddp[v], dp[c]);
            sgt.upd(1, 0, n - 1, id[c], dp[c]);
            dfs(c);
            sgt.upd(1, 0, n - 1, id[c], -INF);
        }
    };
    ddp[0] = 1;
    dp[0] = 1;
    sgt.upd(1, 0, n - 1, id[0], 1);
    dfs(0);
    for (int i = 1; i < n; i++) {
        cout << ddp[i] << ' ';
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