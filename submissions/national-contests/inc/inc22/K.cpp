#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<int> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& arr) {
        if (s == e) {
            tree[v] = arr[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, arr);
        build(v << 1 | 1, mid + 1, e, arr);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int que(int v, int s, int e, int l, int r) {
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

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    vector<vector<int>> to(n + 1), from(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        if (ve[i] == -1) {
            ve[i] = n;
        } else {
            --ve[i];
            to[ve[i]].push_back(i);
            from[i].push_back(ve[i]);
        }
    }
    Segtree sgt(n);
    sgt.build(1, 0, n - 1, ve);
    for (int i = 0; i < n; i++) {
        int sz = to[i].size();
        if (sz == 0) continue;
        int mx = sgt.que(1, 0, n - 1, to[i][0], i - 1);
        if (mx > i) {
            cout << -1 << '\n';
            return;
        }
        for (int j = sz - 1; j >= 1; j--) {
            from[to[i][j]].push_back(to[i][j - 1]);
        }
    }
    vector<bool> vis(n);
    vector<int> order;
    const function<void(int)> dfs = [&](int v) {
        for (auto c : from[v]) {
            if (vis[c]) continue;
            vis[c] = true;
            dfs(c);
        }
        order.push_back(v);
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[order[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << (ans[i] + 1) << ' ';
    }
    cout << '\n';
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