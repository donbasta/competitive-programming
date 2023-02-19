#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return fpow(x, MOD - 2);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
        edges.emplace_back(u, v);
    }
    if (k & 1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> child(n), depth(n);
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        child[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            depth[c] = depth[v] + 1;
            dfs(c, v);
            child[v] += child[c];
        }
    };
    dfs(0, 0);

    vector<ll> pre(n + 1);
    int k2 = k / 2;
    ll cur = 1;
    for (int i = 1; i < k2; i++) {
        cur = (cur * i) % MOD;
    }
    for (int i = k2; i <= n; i++) {
        cur = (cur * i) % MOD;
        pre[i] = cur;
        cur = cur * inv(i - k2 + 1) % MOD;
    }

    ll ans = 0;
    for (auto e : edges) {
        int u = e.first, v = e.second;
        if (depth[u] > depth[v]) swap(u, v);
        ll A = child[v], B = n - A;
        ans = (ans + pre[A] * pre[B] * 2) % MOD;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}