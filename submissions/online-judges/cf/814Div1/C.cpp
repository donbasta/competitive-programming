#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int N = 2e5;

struct Segtree {
    vector<ll> tree;
    Segtree(int n) : tree(4 * n + 5) {}
    void build(int v, int s, int e, const vector<ll>& T) {
        if (s == e) {
            tree[v] = T[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, T);
        build(v << 1 | 1, mid + 1, e, T);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid)
            upd(v << 1, s, mid, idx, val);
        else
            upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
};

void el_psy_congroo() {
    vector<int> divs;

    int n, q;
    cin >> n >> q;

    int cn = n;
    for (int i = 2; i * i <= n; i++) {
        if (cn % i != 0) continue;
        divs.push_back(n / i);
        while (cn % i == 0) cn /= i;
    }
    if (cn > 1) divs.push_back(n / cn);

    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int sz = divs.size();
    vector<vector<ll>> val(sz);
    set<pair<ll, pair<int, int>>> se;
    vector<ll> ve;
    for (int i = 0; i < sz; i++) {
        int d = divs[i];
        val[i].resize(d);
        for (int j = 0; j < n; j++) {
            val[i][j % d] += ar[j] * d;
        }
        for (int j = 0; j < d; j++) {
            ve.push_back(val[i][j]);
        }
    }
    int sszz = ve.size();
    Segtree sgt(sszz);
    sgt.build(1, 0, sszz - 1, ve);
    cout << sgt.tree[1] << '\n';

    while (q--) {
        ll p, x;
        cin >> p >> x;
        --p;
        int cur = 0;
        for (int i = 0; i < sz; i++) {
            int d = divs[i];
            int idx = p % d;
            int pos = cur + idx;
            val[i][idx] += (x - ar[p]) * d;
            sgt.upd(1, 0, sszz - 1, pos, val[i][idx]);
            cur += d;
        }
        cout << sgt.tree[1] << '\n';
        ar[p] = x;
    }
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