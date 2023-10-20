#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 1e5;

int n, l, w;
vector<int> adj[N + 5];
map<pair<int, int>> weights;
bool processed[N + 5];

void dfs_size(int v, int p) {
    sz[v] = 1;
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        dfs_size(c, v);
        sz[v] += sz[c];
    }
}

int get_centroid(int v, int p, int sz_subtree) {
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        if (sz[c] > (sz_subtree / 2)) return get_centroid(c, v, sz_subtree);
    }
    return v;
}

void dfs(int root, int v, int p) {
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        dis[root][c] = dis[root][] dfs(root, c, v);
    }
}

void centroid_decomposition(int v) {
    dfs_size(v, -1);
    int ctr = get_centroid(v, -1, sz[v]);
    dfs(ctr, ctr, -1);
}

void solve() {
    cin >> n >> l >> w;
    for (int i = 0; i < n - 1; i++) {
        int p, w;
        cin >> p >> w;
        --p;
        weights[make_pair(p, i + 1)] = w;
        adj[i + 1].push_back(p);
        adj[p].push_back(i + 1);
    }
    centroid_decomposition(0);
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