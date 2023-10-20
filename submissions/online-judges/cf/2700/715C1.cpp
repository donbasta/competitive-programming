#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 1e5;
const int B = 20;

vector<pair<int, int>> adj[N + 1];
vector<int> child_dec[N + 1];
unordered_map<int, int> cnt_naik[N + 1], cnt_turun[N + 1];

int p10[N + 1], ip10[N + 1];
int v1[N + 1], v2[N + 1], dep[N + 1], tin[N + 1], tout[N + 1], sz[N + 1], par[N + 1];
bool processed[N + 1];
int up[N + 1][B + 1];

int n, mod, timer;
ll ans = 0;

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
ll euler(ll x) {
    ll cx = x;
    ll ret = x;
    for (ll i = 2; i * i <= cx; i++) {
        if (cx % i != 0) continue;
        while (cx % i == 0) cx /= i;
        ret = ret / i * (i - 1);
    }
    if (cx > 1) ret = ret / cx * (cx - 1);
    return ret;
}
void dfs(int v, int p) {
    for (auto c : adj[v]) {
        if (c.first == p) continue;
        dep[c.first] = dep[v] + 1;
        v1[c.first] = (1ll * v1[v] + 1ll * p10[dep[c.first] - 1] * (c.second)) % mod;
        v2[c.first] = (10ll * v2[v] + c.second) % mod;
        dfs(c.first, v);
    }
}
void dfs_lca(int v, int p) {
    tin[v] = timer++;
    up[v][0] = p;
    for (int i = 1; i <= B; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto c : adj[v]) {
        if (c.first == p) continue;
        dfs_lca(c.first, v);
    }
    tout[v] = timer++;
}
bool is_ancestor(int a, int b) {
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = B; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
int naik(int a, int b) {
    int ret = (v1[a] - v1[b]) % mod;
    ret = (1ll * ret * ip10[dep[b]]) % mod;
    if (ret < 0) ret += mod;
    return ret;
};
int turun(int a, int b) {
    int ret = (1ll * v2[b] - 1ll * v2[a] * p10[dep[b] - dep[a]]) % mod;
    if (ret < 0) ret += mod;
    return ret;
};
int num(int a, int b) {
    int l = lca(a, b);
    if (l == a) return turun(a, b);
    if (l == b) return naik(a, b);
    int x = naik(a, l);
    int y = turun(l, b);
    return (1ll * x * (p10[dep[b] - dep[l]]) + y) % mod;
};
int dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
};
void dfs_size(int v, int p) {
    sz[v] = 1;
    for (auto c : adj[v]) {
        if (c.first == p || processed[c.first]) continue;
        dfs_size(c.first, v);
        sz[v] += sz[c.first];
    }
};
int get_centroid(int v, int p, int comp_size) {
    for (auto c : adj[v]) {
        if (c.first == p || processed[c.first]) continue;
        if (sz[c.first] > (comp_size / 2)) return get_centroid(c.first, v, comp_size);
    }
    return v;
}
void cd(int v, int p) {
    dfs_size(v, p);
    int cur_sz = sz[v];
    int ctr = get_centroid(v, p, cur_sz);
    par[ctr] = (p == -1 ? ctr : p);
    processed[ctr] = true;
    for (auto c : adj[ctr]) {
        if (processed[c.first]) continue;
        cd(c.first, ctr);
    }
    processed[ctr] = false;
}
void dfs_dec(int par, int v, int p, bool isi) {
    int naik = num(v, par);
    int turun = num(par, v);
    int simpan_turun = (1ll * turun * ip10[dis(v, par)]) % mod;
    simpan_turun = (mod - simpan_turun) % mod;
    if (simpan_turun < 0) simpan_turun += mod;
    if (isi) {
        cnt_naik[par][naik]++;
        cnt_turun[par][simpan_turun]++;
    } else {
        int cari_naik = (1ll * turun * ip10[dis(v, par)]) % mod;
        cari_naik = (mod - cari_naik) % mod;
        if (cari_naik < 0) cari_naik += mod;
        if (cnt_naik[par].count(cari_naik)) {
            ans += cnt_naik[par][cari_naik];
        }
        if (cnt_turun[par].count(naik)) {
            ans += cnt_turun[par][naik];
        }
    }
    for (auto c : child_dec[v]) {
        dfs_dec(par, c, v, isi);
    }
}

void solve() {
    cin >> n >> mod;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int ip;
    if (mod == 1)
        ip = 1;
    else
        ip = fpow(10, euler(mod) - 1, mod);
    p10[0] = ip10[0] = 1;
    for (int i = 1; i <= n; i++) {
        p10[i] = (1ll * p10[i - 1] * 10) % mod;
        ip10[i] = (1ll * ip10[i - 1] * ip) % mod;
    }

    dfs(0, 0);
    dfs_lca(0, 0);
    cd(0, -1);

    for (int i = 0; i < n; i++) {
        if (par[i] == i) continue;
        child_dec[par[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cnt_naik[i][0] = cnt_turun[i][0] = 1;
        for (auto c : child_dec[i]) {
            dfs_dec(i, c, i, false);
            dfs_dec(i, c, i, true);
        }
    }
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