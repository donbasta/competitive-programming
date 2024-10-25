#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Segtree {
    vector<ll> tree, lz;
    Segtree(int n) : tree(4 * n + 5), lz(4 * n + 5) {}
    void push(int v) {
        if (lz[v] == 0) return;
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
        tree[v << 1] += lz[v];
        tree[v << 1 | 1] += lz[v];
        lz[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, ll val) {
        if (s == l && e == r) {
            lz[v] += val;
            tree[v] += val;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    ll get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return min(
            get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<ll> ag(n);
    for (int i = 0; i < n; i++) {
        cin >> ag[i];
    }
    vector<ll> avg(m);
    vector<vector<ll>> ags(m), avg1(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        ags[i].resize(k);
        avg1[i].resize(k);
        ll sum = 0;
        for (int j = 0; j < k; j++) {
            cin >> ags[i][j];
            sum += ags[i][j];
        }
        avg[i] = (sum + k - 1) / k;
        for (int j = 0; j < k; j++) {
            avg1[i][j] = (sum - ags[i][j] + k - 2) / (k - 1);
        }
    }
    vector<pair<ll, vector<ll>>> ve;
    for (auto e : ag) ve.emplace_back(e, vector<ll>{1});
    for (int i = 0; i < m; i++) {
        ve.emplace_back(avg[i], vector<ll>{0, i, -1});
        for (int j = 0; j < avg1[i].size(); j++) {
            ve.emplace_back(avg1[i][j], vector<ll>{0, i, j});
        }
    }
    sort(ve.begin(), ve.end());
    int sz = ve.size();
    Segtree sgt(sz);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(ve.begin(), ve.end(), make_pair(ag[i], vector<ll>{1})) - ve.begin();
        sgt.upd(1, 0, sz - 1, 0, idx, 1);
    }
    vector<int> idx_group(m);
    for (int i = 0; i < m; i++) {
        int idx = lower_bound(ve.begin(), ve.end(), make_pair(avg[i], vector<ll>{0, i, -1})) - ve.begin();
        idx_group[i] = idx;
        sgt.upd(1, 0, sz - 1, 0, idx, -1);
    }

    string ans;
    for (int i = 0; i < m; i++) {
        sgt.upd(1, 0, sz - 1, 0, idx_group[i], 1);
        for (int j = 0; j < avg1[i].size(); j++) {
            int idx = lower_bound(ve.begin(), ve.end(), make_pair(avg1[i][j], vector<ll>{0, i, j})) - ve.begin();
            sgt.upd(1, 0, sz - 1, 0, idx, -1);
            if (sgt.get(1, 0, sz - 1, 0, sz - 1) >= 0) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            sgt.upd(1, 0, sz - 1, 0, idx, 1);
        }
        sgt.upd(1, 0, sz - 1, 0, idx_group[i], -1);
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