#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 2e5;
const int MOD = 998244353;
int fc[N + 5], ifc[N + 5];

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (1ll * fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;
    }
}

int C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    int ret = (1ll * fc[a] * ifc[b]) % MOD;
    ret = (1ll * ret * ifc[a - b]) % MOD;
    return ret;
}

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n);
    const int B = 20;
    vector<int> tin(n), tout(n), D(n), mid(n), bot(n), D_tri(n), D_x(n);
    int T = 0;
    vector<vector<int>> up(n, vector<int>(B));
    set<pair<int, int>> backedge;
    const function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = T++;
        up[v][0] = p;
        for (int i = 1; i < B; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (vis[c]) {
                if (c != up[v][1]) continue;
                mid[up[v][0]] = 1;
                bot[v] = 1;
                backedge.emplace(v, c);
            } else {
                D[c] = D[v] + 1;
                vis[c] = true;
                dfs(c, v);
            }
        }
        tout[v] = T++;
    };
    auto is_ancestor = [&](int a, int b) -> bool {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    };
    auto lca = [&](int a, int b) -> int {
        if (is_ancestor(a, b)) return a;
        if (is_ancestor(b, a)) return b;
        for (int i = B - 1; i >= 0; i--) {
            if (!is_ancestor(up[a][i], b)) {
                a = up[a][i];
            }
        }
        return up[a][0];
    };
    auto dis = [&](int a, int b) -> int {
        return D[a] + D[b] - 2 * D[lca(a, b)];
    };
    auto kth_ancestor = [&](int a, int k) -> int {
        if (k == 0) return a;
        for (int i = B - 1; i >= 0; i--) {
            if (k >= (1 << i)) {
                k -= (1 << i);
                a = up[a][i];
            }
        }
        return a;
    };
    const function<void(int, int)> dfs_tr = [&](int v, int p) -> void {
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (c == up[v][1]) continue;
            if (backedge.count(make_pair(c, v))) continue;
            D_tri[c] = D_tri[v] + mid[c];
            if (mid[c]) D_x[c] = D_x[v] + 1;
            if (bot[c]) D_x[c] = D_x[v] - 1;
            dfs_tr(c, v);
        }
    };
    auto count_triangles = [&](int a, int b) -> int {
        return D_tri[a] + D_tri[b] - 2 * D_tri[lca(a, b)];
    };
    auto count_x = [&](int a, int b) -> int {
        return D_x[a] + D_x[b] - 2 * D_x[lca(a, b)];
    };
    vis[0] = true;
    dfs(0, 0);
    dfs_tr(0, 0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, f, k;
        cin >> s >> f >> k;
        --s, --f;
        if (s == f) {
            cout << (k == 0) << '\n';
            continue;
        }
        int L = lca(s, f);
        int Dis = dis(s, f);
        int Tri = count_triangles(s, f);
        int X = count_x(s, f);
        Dis += X;

        if (mid[L]) {
            bool ok = false;
            if (s != L) {
                int dd = D[s] - D[L];
                int pp = kth_ancestor(s, dd - 1);
                ok = ok || bot[pp];
            }
            if (f != L) {
                int dd = D[f] - D[L];
                int pp = kth_ancestor(f, dd - 1);
                ok = ok || bot[pp];
            }
            if (ok) {
                Tri++;
                Dis += 2;
            }
        }
        int ans = C(Tri, Dis - k);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init_fac();

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}