#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 1e6;

int getLucky(const string& s) {
    int mn = INF, mx = -INF;
    for (auto c : s) {
        int cur_dig = c - '0';
        mn = min(mn, cur_dig);
        mx = max(mx, cur_dig);
    }
    return mx - mn;
}

int combine(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int pa = getLucky(sa);
    int pb = getLucky(sb);
    if (pa > pb) return a;
    return b;
}

struct Segtree {
    vector<int> tree;
    Segtree() {
        tree.resize(4 * M + 5);
    }
    void build(int v, int s, int e) {
        if (s == e) {
            tree[v] = s;
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return combine(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

void solve() {
    int n;
    cin >> n;
    Segtree sgt;
    sgt.build(1, 1, M);
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << sgt.get(1, 1, M, l, r) << '\n';
    }
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