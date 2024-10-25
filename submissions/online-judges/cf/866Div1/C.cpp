#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        deg[i] = adj[i].size();
    }
    if (n <= 3) {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> sz(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            sz[v] += sz[c];
        }
    };
    dfs(0, 0);
    bool failed = false;
    const function<void(int, int)> dfs_reroot = [&](int v, int p) {
        int lol = 0;
        for (auto c : adj[v]) {
            lol += (sz[c] > 1);
        }
        // cerr << v << ' ' << lol << '\n';
        failed = (failed || (lol >= 3));
        for (auto c : adj[v]) {
            if (c == p) continue;
            sz[v] = n - sz[c];
            sz[c] = n;
            dfs_reroot(c, v);
            sz[c] = n - sz[v];
            sz[v] = n;
        }
    };
    dfs_reroot(0, 0);
    if (failed) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    int st = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) continue;
        ll leaves = 0;
        for (auto c : adj[i]) {
            leaves += deg[c] == 1;
        }
        if (deg[i] - leaves <= 1) {
            st = i;
        }
    }
    assert(st != -1);
    // cerr << st << '\n';
    vector<int> path;
    const function<void(int, int)> dfs_path = [&](int v, int p) {
        path.push_back(v);
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (deg[c] == 1) continue;
            dfs_path(c, v);
        }
    };
    dfs_path(st, -1);
    int len = path.size();
    // for (auto p : path) {
    //     cerr << p << ' ';
    // }
    // cerr << '\n';

    vector<int> res;
    int cur = 0;
    while (cur < len) {
        if (cur & 1) {
            res.push_back(path[cur]);
        } else {
            for (auto c : adj[path[cur]]) {
                if (deg[c] == 1) res.push_back(c);
            }
        }
        cur++;
    }
    cur--;
    while (cur >= 0) {
        if (cur & 1) {
            for (auto c : adj[path[cur]]) {
                if (deg[c] == 1) res.push_back(c);
            }
        } else {
            res.push_back(path[cur]);
        }
        cur--;
    }
    assert(res.size() == n);
    for (auto e : res) {
        cout << (e + 1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}