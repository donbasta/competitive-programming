#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template <typename T, class F = function<T(const T&, const T&)>>
class Segtree {
public:
    int n;
    vector<T> t;
    F func;

    Segtree (int _n, const F& _f) : n(_n), func(_f) {
        t.resize(4 * _n + 5);
    }
    void build (int v, int s, int e, const vector<T>& ar) {
        if (s == e) {
            t[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build (v << 1, s, mid, ar);
        build (v << 1 | 1, mid + 1, e, ar);
        t[v] = func(t[v << 1], t[v << 1 | 1]);
    }
    void upd (int v, int s, int e, int pos, const T& val) {
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
        t[v] = func(t[v << 1], t[v << 1 | 1]);
    }
    T que (int v, int s, int e, int l, int r) {
        if (l == s && r == e) { 
            return t[v]; 
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return que(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return que(v << 1 | 1, mid + 1, e, l, r);
        } else {
            return func(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> ar[i];
    }

    function<int(int, int)> fmax = [&](int a, int b) -> int {return max(a, b);};
    Segtree<int> sgt(m, fmax);
    sgt.build(1, 1, m, ar);

    int q;
    cin >> q;
    while (q--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        int dx = abs(xs - xf), dy = abs(ys - yf);
        if ((dx % k != 0) || (dy % k != 0)) {
            cout << "NO" << '\n';
            continue;
        }
        int lol = xs % k;
        int highest = ((n - lol) / k) * k + lol;
        if (ys > yf) swap(ys, yf);
        int haha = sgt.que(1, 1, m, ys, yf);
        if (haha >= highest) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
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
