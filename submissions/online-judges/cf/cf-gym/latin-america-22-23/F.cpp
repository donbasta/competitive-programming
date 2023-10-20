#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n[2];
    vector<vector<set<int>>> adj(2);
    vector<vector<pair<int, int>>> edges(2);
    for (int i = 0; i < 2; i++) {
        cin >> n[i];
        adj[i].resize(n[i]);
        for (int j = 0; j < n[i] - 1; j++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[i][u].insert(v);
            adj[i][v].insert(u);
            edges[i].emplace_back(u, v);
        }
    }

    int avail = 0;
    map<vector<int>, int> hashes;
    vector<vector<int>> hash_root_2(n[1], vector<int>(n[1]));
    const function<void(int, int, int)> dfs_2 = [&](int root, int v, int p) {
        vector<int> tmp;
        for (auto c : adj[1][v]) {
            if (c == p) continue;
            dfs_2(root, c, v);
            tmp.push_back(hash_root_2[root][c]);
        }
        sort(tmp.begin(), tmp.end());
        if (hashes.count(tmp)) {
            hash_root_2[root][v] = hashes[tmp];
        } else {
            hash_root_2[root][v] = avail++;
            hashes[tmp] = hash_root_2[root][v];
        }
    };
    set<int> hash_t2;
    for (int i = 0; i < n[1]; i++) {
        dfs_2(i, i, -1);
        hash_t2.insert(hash_root_2[i][i]);
    }
    for (auto c : hash_t2) {
        cerr << c << '\n';
    }
    cerr << '\n';

    bool ok = false;
    vector<int> hash_root_1(n[0]);
    const function<void(int, int)> dfs_1 = [&](int v, int p) {
        vector<int> tmp;
        for (auto c : adj[0][v]) {
            if (c == p) continue;
            dfs_1(c, v);
            tmp.push_back(hash_root_1[c]);
        }
        sort(tmp.begin(), tmp.end());
        if (hashes.count(tmp)) {
            hash_root_1[v] = hashes[tmp];
        } else {
            hash_root_1[v] = avail++;
            hashes[tmp] = hash_root_1[v];
        }

        if (hash_t2.count(hash_root_1[v])) {
            ok = true;
        }
    };

    dfs_1(0, 0);
    for (int i = 0; i < n[0] - 1; i++) {
        int u = edges[0][i].first, v = edges[0][i].second;
        adj[0][u].erase(v), adj[0][v].erase(u);
        dfs_1(u, -1);
        dfs_1(v, -1);
        adj[0][u].insert(v), adj[0][v].insert(u);
    }
    if (ok) {
        cout << "Y" << '\n';
        return;
    }

    cout << "N" << '\n';
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