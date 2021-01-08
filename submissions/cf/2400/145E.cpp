#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string lucky;
int n, m;

struct node {
    int c4, c7, inc, dec;
    node() {}
    node(int num) {
        inc = dec = 1;
        if (num == '4') { c4 = 1, c7 = 0; }
        if (num == '7') { c4 = 0, c7 = 1; }
    }
    void rev() {
        swap(c4, c7);
        swap(inc, dec);
    }
};

node merge(node a, node b) {
    node ret;
    ret.c4 = a.c4 + b.c4;
    ret.c7 = a.c7 + b.c7;
    ret.inc = max(a.c4 + b.inc, a.inc + b.c7);
    ret.dec = max(a.c7 + b.dec, a.dec + b.c4);
    return ret;
}

struct Segtree {
    vector<node> t;
    vector<bool> lz;
    Segtree(int n) {
        t.resize(4 * n + 5);
        lz.resize(4 * n + 5);
    }
    void build (int v, int s, int e) {
        if (s == e) {
            t[v] = node(lucky[s - 1]);
            return;
        }
        int mid = (s + e) >> 1;
        build (v << 1, s, mid);
        build (v << 1 | 1, mid + 1, e);
        t[v] = merge (t[v << 1], t[v << 1 | 1]);
    }
    void push (int v) {
        if (!lz[v]) return;
        lz[v] = 0;
        lz[v << 1] = lz[v << 1] ^ 1;
        lz[v << 1 | 1] = lz[v << 1 | 1] ^ 1;
        t[v << 1].rev();
        t[v << 1 | 1].rev();
    }
    void update (int v, int s, int e, int l, int r) {
        if (l > e || r < s || l > r) { return; }
        if (l == s && r == e) {
            lz[v] = lz[v] ^ 1;
            t[v].rev();
            return;
        }
        push (v);
        int mid = (s + e) >> 1;
        update (v << 1, s, mid, l, min(mid, r));
        update (v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
};

void solve() {
    cin >> n >> m;
    cin >> lucky;
    Segtree tree(n);
    tree.build(1, 1, n);
    while (m--) {
        string query;
        cin >> query;
        if (query == "count") {
            cout << tree.t[1].inc << '\n';
        } else if (query == "switch") {
            int l, r;
            cin >> l >> r;
            tree.update(1, 1, n, l, r);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}