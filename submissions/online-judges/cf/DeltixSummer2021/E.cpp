#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;
const ll INF = 1e18;
ll a[N + 5], b[N + 5], pre[N + 5];
ll t[4 * N + 5];

int n, q;

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = pre[s];
        return;
    }
    int mid = (s + e) >> 1;
    build (v << 1, s, mid);
    build (v << 1 | 1, mid + 1, e);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

ll query(int v, int s, int e, int l, int r) {
    if (r < s || l > e || r < l) {
        return -INF;
    }
    if (l == s && r == e) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    return max(
        query(v << 1, s, mid, l, min(r, mid)),
        query(v << 1 | 1, mid + 1, e, max(l, mid + 1), r)
    );
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (b[i] - a[i]);
    }
    build (1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll cek = pre[r] - pre[l - 1];
        if (cek != 0) {
            cout << -1 << '\n';
            continue;
        }
        ll mx = query(1, 1, n, l, r);
        cout << mx - pre[l - 1] << '\n';
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