#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
int sz[N + 5], tin[N + 5];
vector<int> adj[N + 5];
vector<int> adj2[N + 5];

int t[4 * N + 5], lz[4 * N + 5];

int timer = 0;
int n, q;

void dfs(int v, int p) {
    for (auto e : adj[v]) {
        if (e == p) continue;
        for (auto c : adj[e]) {
            if (c == v) continue;
            adj2[v].emplace_back(c);
        }
        dfs(e, v);
    }
}

void dfs_euler(int v, int p) {
    tin[v] = ++timer;
    sz[v] = 1;
    for (auto e : adj2[v]) {
        if (e == p) continue;
        dfs_euler(e, v);
        sz[v] += sz[e];
    }
}

void push (int v, int s, int e) {
    if (!lz[v]) return;
    int mid = (s + e) >> 1;
    if ((mid - s + 1) & 1) t[v << 1] ^= lz[v];
    if ((e - mid) & 1) t[v << 1 | 1] ^= lz[v];
    lz[v << 1] ^= lz[v];
    lz[v << 1 | 1] ^= lz[v];
    lz[v] = 0;
}

void upd (int v, int s, int e, int l, int r, int xr) {
    if (l > r || l > e || r < s) return;
    if (l == s && r == e) {
        if ((r - l + 1) & 1) t[v] ^= xr;
        lz[v] ^= xr;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    upd (v << 1, s, mid, l, min(mid, r), xr);
    upd (v << 1 | 1, mid + 1, e, max(l, mid + 1), r, xr);
    t[v] = t[v << 1] ^ t[v << 1 | 1];
}

int que (int v, int s, int e, int pos) {
    if (s == e) { return t[v]; }
    push(v, s, e);
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        return que (v << 1, s, mid, pos);
    } else {
        return que (v << 1 | 1, mid + 1, e, pos);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, 0);
    for (auto e : adj[1]) {
        adj2[0].emplace_back(e);
    }
    dfs_euler(1, 0);
    dfs_euler(0, 0);
    cin >> q;
    while (q--) {
        int tp, u, v;
        cin >> tp;
        if (tp == 1) {
            cin >> u >> v;
            upd(1, 1, n + 1, tin[u], tin[u] + sz[u] - 1, v);
        } else if (tp == 2) {
            cin >> u;
            int a = que(1, 1, n + 1, tin[u]);
            cout << a << '\n';
        }
    }
    return;
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