#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    int n;
    vector<int> tree, lz;
    Segtree(int n) : n(n) {
        tree.resize(4 * n + 5);
        lz.resize(4 * n + 5);
    }
    void push(int v) {
        if (lz[v] == 0) return;
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
        tree[v << 1] += lz[v];
        tree[v << 1 | 1] += lz[v];
        lz[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            lz[v] += val;
            tree[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        push(v);
        if (r <= mid)
            upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        push(v);
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int l, int r, int val) {
        upd(1, 0, n - 1, l, r, val);
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ve1, ve2;
    vector<int> comp;
    comp.push_back(1);
    comp.push_back(m);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 1 && r == m) continue;
        comp.push_back(l);
        comp.push_back(r);
        ve1.emplace_back(l, r);
        ve2.emplace_back(l, r);
    }
    n = ve1.size();
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    unordered_map<int, int> id;
    for (int i = 0; i < (int)comp.size(); i++) {
        id[comp[i]] = i;
    }
    sort(ve1.begin(), ve1.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second < b.second;
    });
    sort(ve2.begin(), ve2.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        return a.first < b.first;
    });

    int sz = comp.size();
    Segtree sgt(sz);
    for (int i = 0; i < n; i++) {
        if (ve2[i].first == 1) continue;
        sgt.upd(id[ve2[i].first], id[ve2[i].second], 1);
    }
    int ans = sgt.get(0, sz - 1);
    int cur = 0;
    while (cur < n && ve2[cur].first == 1) cur++;
    for (int i = 0; i < n; i++) {
        if (ve1[i].second == m) break;
        sgt.upd(id[ve1[i].first], id[ve1[i].second], 1);
        while (cur < n && ve2[cur].first <= ve1[i].second + 1) {
            sgt.upd(id[ve2[cur].first], id[ve2[cur].second], -1);
            cur++;
        }
        int tmp = sgt.get(0, id[ve1[i].second]);
        if (cur < n) tmp = max(tmp, sgt.get(id[ve2[cur].first], sz - 1));
        ans = max(ans, tmp);
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