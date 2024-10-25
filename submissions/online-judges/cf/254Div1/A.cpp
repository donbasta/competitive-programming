#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct Segtree {
    vector<ll> tree, col;
    vector<bool> same;
    Segtree(int n) : tree(4 * n + 5), col(4 * n + 5), pt(4 * n + 5) {}
    void build(int v, int s, int e) {
        if (s == e) {
            col[v] = s;
            same[v] = true;
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1);
    }
};

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tp, l, r, x;
        cin >> tp;
        if (tp == 1) {
            cin >> l >> r >> x;
        } else if (tp == 2) {
            cin >> l >> r;
        }
    }
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