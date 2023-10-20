#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[i][a].push_back(b);
            adj[i][b].push_back(a);
        }
    }
    vector<vector<int>> sz(2, vector<int>(n));
    const function<void(int, int, int)> dfs_size = [&](int v, int p, int idx) {
        sz[idx][v] = 1;
        for (auto c : adj[idx][v]) {
            if (c == p) continue;
            dfs_size(c, v, idx);
            sz[idx][v] += sz[idx][c];
        }
    };
    dfs_size(0, 0, 0), dfs_size(0, 0, 1);
    vector<vector<int>> centroids(2);
    const function<void(int, int, int)> get_centroid = [&](int v, int p, int idx) {
        for (auto c : adj[idx][v]) {
            if (c == p) continue;
            if (sz[idx][c] > (n / 2)) {
                get_centroid(c, v, idx);
                return;
            } else if (sz[idx][c] == (n / 2) && (n % 2 == 0)) {
                get_centroid(c, v, idx);
            }
        }
        centroids[idx].push_back(v);
    };
    get_centroid(0, 0, 0), get_centroid(0, 0, 1);
    map<vector<int>, int> hashes;
    int avail = 0;
    vector<vector<vector<int>>> hash_root(2);
    for (int i = 0; i < 2; i++) {
        hash_root[i].assign(centroids[i].size(), vector<int>(n));
    }
    const function<void(int, int, int, int)> dfs_hash = [&](int v, int p, int i, int j) {
        vector<int> tmp;
        for (auto c : adj[i][v]) {
            if (c == p) continue;
            dfs_hash(c, v, i, j);
            tmp.push_back(hash_root[i][j][c]);
        }
        sort(tmp.begin(), tmp.end());
        if (hashes.find(tmp) != hashes.end()) {
            hash_root[i][j][v] = hashes[tmp];
        } else {
            hash_root[i][j][v] = avail++;
            hashes[tmp] = hash_root[i][j][v];
        }
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (int)centroids[i].size(); j++) {
            dfs_hash(centroids[i][j], centroids[i][j], i, j);
        }
    }
    for (int i = 0; i < (int)centroids[0].size(); i++) {
        for (int j = 0; j < (int)centroids[1].size(); j++) {
            if (hash_root[0][i][centroids[0][i]] == hash_root[1][j][centroids[1][j]]) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}