#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Segtree {
    vector<ll> t, lz;
    Segtree(int n) {
        t.resize(4 * n + 5), lz.resize(4 * n + 5);
    } 
    void build (int v, int s, int e) {
        if (s == e) {
            t[v] = 0;
        }
    }
    
}

void solve() {
    cin >> n >> m;
    Segtree tree(n);
    tree.build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            int x;
            cin >> x;
            tree.update(1, 1, n, l, r, x);
        } else if (type == 2) {
            cout << tree.ask(1, 1, n, l, r) << '\n';
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