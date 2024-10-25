#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<int> tree;
    Segtree(int n) : tree(4 * n + 5, -1) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = max(tree[v], val);
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (l > r) return -1;
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(
            get(v << 1, s, mid, l, mid),
            get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> B(n), I(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> I[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    vector<int> tmp = I;
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    int sz = tmp.size();
    map<int, int> mp;
    for (int i = 0; i < sz; i++) {
        mp[tmp[i]] = i;
    }

    Segtree sgt(sz);

    vector<vector<int>> balls(n);
    for (int i = 0; i < n; i++) {
        balls[i] = vector<int>{B[i], mp[I[i]], R[i]};
    }
    sort(balls.begin(), balls.end());
    int ans = 0;
    for (int i = n - 1; i >= 0;) {
        int cur = balls[i][0], j = i;
        while (j >= 0 && balls[j][0] == cur) {
            int bat = balls[j][1];
            if (sgt.get(1, 0, sz - 1, bat + 1, sz - 1) > balls[j][2]) {
                ans++;
            }
            j--;
        }
        for (int k = i; k > j; k--) {
            sgt.upd(1, 0, sz - 1, balls[k][1], balls[k][2]);
        }
        i = j;
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