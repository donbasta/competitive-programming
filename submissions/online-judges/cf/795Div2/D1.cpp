#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 2e9;

struct Segtree {
    int n;
    vector<ll> t;
    function<ll(ll, ll)> Func;
    Segtree (int _n, function<ll(ll, ll)> _f) : n(_n), Func(_f) {
        t.resize(4 * _n + 5);
    }
    void build (int v, int s, int e, const vector<ll>& ar) {
        if (s == e) {
            t[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build (v << 1, s, mid, ar);
        build (v << 1 | 1, mid + 1, e, ar);
        t[v] = Func(t[v << 1], t[v << 1 | 1]);
    }
    ll que (int v, int s, int e, int l, int r) {
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
    int n;
    cin >> n;
    vector<ll> ar(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }
    function<ll(ll, ll)> fmin = [&](ll a, ll b) -> ll {return min(a, b);};
    function<ll(ll, ll)> fmax = [&](ll a, ll b) -> ll {return max(a, b);};
    Segtree sgt = Segtree(n, fmin);
    Segtree sgt2 = Segtree(n, fmax);
    sgt.build(1, 1, n, pre);
    sgt2.build(1, 1, n, ar);
    bool ok = true;
    for (int i = 2; i <= n; i++) {
        int l = 1, r = (i - 1);
        while (l < r) {
            int mid = (l + r) / 2;
            ll cek = sgt2.que(1, 1, n, mid + 1, r);
            if (cek >= ar[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int j = l;
        if (ar[j] < ar[i]) {
            j = 0;
        }
        // then ar[k] + ... + ar[i] <= ar[i] for k = j+1, ..., i
        // pre[i - 1] - pre[k - 1] <= 0 for k = j+1, ..., i
        ll mn = sgt.que(1, 1, n, max(1, j), i - 1);
        if (j == 0) mn = min(mn, 0LL);
        bool lol = (j ? (pre[i] <= pre[j]) : true);
        ok &= (mn >= pre[i - 1]) && lol;
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}