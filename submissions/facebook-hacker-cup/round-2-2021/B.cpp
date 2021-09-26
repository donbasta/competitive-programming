#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, l;
vector<vector<int>> adj, fr;

int timer;
vector<int> tin, tout, ar;
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    ar.resize(n + 1);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n + 1, vector<int>(l + 1));
    dfs(root, root);
}

void reset() {
    tin.clear();
    tout.clear();
    ar.clear();
    fr.clear();
    adj.clear();
}

void dfs2(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs2(u, v);
        ar[v] += ar[u];
    }
}

void solve() {
    cin >> n;
    adj.resize(n + 1);
    fr.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    preprocess(1);
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f;
        fr[f].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int sz = (int) fr[i].size();
        if (sz <= 1) continue;
        int lca = fr[i][0];
        for (int j = 1; j < sz; j++) {
            lca = LCA(lca, fr[i][j]);
        }
        for (int j = 0; j < sz; j++) {
            ar[fr[i][j]]++;
            ar[lca]--;
        }
    }
    dfs2(1, 1);

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (ar[i] == 0LL) ans++;
    }
    cout << ans << '\n';

    reset();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}