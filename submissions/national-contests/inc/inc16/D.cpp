#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Segtree {
    int n;
    vector<int> t;
    function<int(int, int)> Func;
    Segtree (int _n, function<int(int, int)> _f) : n(_n), Func(_f) {
        t.resize(4 * _n + 5);
    }
    void build (int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            t[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build (v << 1, s, mid, ar);
        build (v << 1 | 1, mid + 1, e, ar);
        t[v] = Func(t[v << 1], t[v << 1 | 1]);
    }
    void upd (int v, int s, int e, int pos, int val) {
        if (s == e) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            upd (v << 1, s, mid, pos, val);
        } else {
            upd (v << 1 | 1, mid + 1, e, pos, val);
        }
        t[v] = Func(t[v << 1], t[v << 1 | 1]);
    }
    int que (int v, int s, int e, int l, int r) {
        if (l == s && r == e) { 
            return t[v]; 
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return que(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return que(v << 1 | 1, mid + 1, e, l, r);
        } else {
            return Func(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ar(n + 1), br(n);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        if (i > 1) {
            br[i - 1] = ar[i] - ar[i - 1];
        }
    }
    if (n > 1) {
        Segtree sgtMin = Segtree(n - 1, [&](int a, int b) -> int {return min(a, b);});
        Segtree sgtMax = Segtree(n - 1, [&](int a, int b) -> int {return max(a, b);});
        sgtMin.build(1, 1, n - 1, br);
        sgtMax.build(1, 1, n - 1, br);
        while (q--) {
            int type, u, v;
            cin >> type >> u >> v;
            if (type == 1) {
                if (u > 1) {
                    sgtMin.upd(1, 1, n - 1, u - 1, v - ar[u - 1]);
                    sgtMax.upd(1, 1, n - 1, u - 1, v - ar[u - 1]); 
                }
                if (u <= n - 1) {
                    sgtMin.upd(1, 1, n - 1, u, ar[u + 1] - v);
                    sgtMax.upd(1, 1, n - 1, u, ar[u + 1] - v);
                }
                ar[u] = v;
            } else if (type == 2) {
                if (u == v) {
                    cout << "YES" << '\n';
                    continue;
                } 
                int mn = sgtMin.que(1, 1, n - 1, u, v - 1);
                int mx = sgtMax.que(1, 1, n - 1, u, v - 1);
                cout << (mn == mx ? "YES" : "NO") << '\n';
            }
        }
    } else {
        while (q--) {
            int type, u, v;
            cin >> type >> u >> v;
            if (type == 2) {
                cout << "YES" << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ":\n";
        solve();
    }
  
    return 0;
}