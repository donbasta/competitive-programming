#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;

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
    int n;
    cin >> n;
    vector<pair<int, int>> p(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    auto fmin = [&](pair<int, int> a, pair<int, int> b) -> pair<int, int> {return min(a, b);};
    Segtree<pair<int, int>> MN(2 * n, fmin);
    MN.build(1, 1, 2 * n, p);
    vector<int> ans;
    const auto solve = [&](const auto& self, int l, int r) -> void {
        if (l >= r) return;
        pair<int, int> mn = MN.que(1, 1, 2 * n, l, r);
        int sep1 = mn.second;
        int nw;
        // cerr << l << ' ' << r << ' ' << mn.second << ' ' << mx.second << '\n';
        if (mn.second % 2 == 0) {
            if (mn.second == l) {
                nw = l + 1;
                ans.push_back(l);
            } else {
                nw = mn.second - 1;
                ans.push_back(nw);
            }
            MN.upd(1, 1, 2 * n, mn.second, make_pair(p[nw].first, mn.second));
            swap(p[nw].first, p[mn.second].first);
            sep1 = nw;
        }
        assert(sep1 % 2 == 1);
        self(self, l, sep1 - 1);
        self(self, sep1 + 1, r);
    };

    solve(solve, 1, 2 * n);
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (i % 2 == 0) {
            assert(p[i].first > p[i + 1].first);
        }   
        if (i % 2 == 1) {
            assert(p[i].first < p[i + 1].first);
        }
    }
    // for (int i = 1; i <= 2 * n; i++) {
    //     cerr << p[i].first << ' ';
    // }
    cout << ans.size() << '\n';
    if (ans.size() == 0) {
        return;
    }
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    // cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
