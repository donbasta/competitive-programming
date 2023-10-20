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
        for (int e = 0; e < n - 1; e++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[i][a].push_back(b);
            adj[i][b].push_back(a);
        }
    }
    int avail = 0;
    map<vector<int>, int> hashes;
    vector<vector<int>> hash_root(2, vector<int>(n));
    const function<void(int, int, int)> dfs = [&](int v, int p, int idx) {
        vector<int> tmp;
        for (auto c : adj[idx][v]) {
            if (c == p) continue;
            dfs(c, v, idx);
            tmp.push_back(hash_root[idx][c]);
        }
        sort(tmp.begin(), tmp.end());
        if (hashes.find(tmp) != hashes.end()) {
            hash_root[idx][v] = hashes[tmp];
        } else {
            hash_root[idx][v] = avail++;
            hashes[tmp] = hash_root[idx][v];
        }
    };
    for (int i = 0; i < 2; i++) {
        dfs(0, 0, i);
    }
    if (hash_root[0][0] == hash_root[1][0]) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
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