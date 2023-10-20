#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 2e5;

int n, k, mx_depth;
vector<int> adj[M + 1];
ll ans;
bool processed[M];
int sz[M], cnt[M + 1]{1};

int dfs_size(int v, int p) {
    sz[v] = 1;
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        sz[v] += dfs_size(c, v);
    }
    return sz[v];
}

int get_centroid(int v, int p, int comp_size) {
    for (auto c : adj[v]) {
        if (c == p || processed[c]) continue;
        if (sz[c] > (comp_size / 2)) return get_centroid(c, v, comp_size);
    }
    return v;
}

void dfs_path(int v, int p, bool is_filling, int depth) {
    if (depth > k) return;
    mx_depth = max(mx_depth, depth);
    if (is_filling)
        cnt[depth]++;
    else
        ans += cnt[k - depth];
    for (int c : adj[v]) {
        if (c == p || processed[c]) continue;
        dfs_path(c, v, is_filling, depth + 1);
    }
}

void centroid_decomposition(int v) {
    int ctr = get_centroid(v, -1, dfs_size(v, -1));
    processed[ctr] = true;
    mx_depth = 0;
    for (auto c : adj[ctr]) {
        if (processed[c]) continue;
        dfs_path(c, ctr, false, 1);
        dfs_path(c, ctr, true, 1);
    }
    fill(cnt + 1, cnt + mx_depth + 1, 0);
    for (auto c : adj[ctr]) {
        if (processed[c]) continue;
        centroid_decomposition(c);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    centroid_decomposition(0);
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