#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;
const int N = 1e5;
ll ar[N + 5];

struct node {
    ll val, mx;
    ll minPref, maxPref, minSuf, maxSuf;
    node () {}
    node (ll n) : val(n) {
        mx = n;
        minPref = n;
        maxPref = n;
        minSuf = n;
        maxSuf = n;
    }
} t[4 * N + 5];

node merge(const node& a, const node& b) {
    node ret(a.val * b.val);
    ret.minPref = min({a.minPref, a.val * b.minPref, a.val * b.maxPref});
    ret.maxPref = max({a.maxPref, a.val * b.maxPref, a.val * b.minPref});
    ret.minSuf = min({b.minSuf, b.val * a.minSuf, b.val * a.maxSuf});
    ret.maxSuf = max({b.maxSuf, b.val * a.maxSuf, b.val * a.minSuf});
    ret.mx = max({a.mx, b.mx});
    ret.mx = max({ret.mx, a.minSuf * b.minPref, a.minSuf * b.maxPref, a.maxSuf * b.minPref, a.maxSuf * b.maxPref});
    return ret;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = node(ar[s]);
        return;
    }
    int mid = (s + e) >> 1;
    build (v << 1, s, mid);
    build (v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

node que(int v, int s, int e, int l, int r) {
    if (l == s && r == e) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    if (l > mid) {
        return que(v << 1 | 1, mid + 1, e, l, r);
    } else if (r <= mid) {
        return que(v << 1, s, mid, l, r);
    } else {
        return merge (
            que(v << 1, s, mid, l, mid),
            que(v << 1 | 1, mid + 1, e, mid + 1, r)
        );
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    build (1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll ret = que(1, 1, n, l, r).mx;
        cout << ret << '\n';
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