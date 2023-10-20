#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int avail = 0;
    map<vector<int>, int> hashes;
    vector<int> hash_root(n);
    const function<void(int, int)> dfs = [&](int v, int p) {
        vector<int> tmp;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            tmp.push_back(hash_root[c]);
        }
        sort(tmp.begin(), tmp.end());
        if (hashes.find(tmp) != hashes.end()) {
            hash_root[v] = hashes[tmp];
        } else {
            hash_root[v] = avail++;
            hashes[tmp] = hash_root[v];
        }
    };
    dfs(0, 0);
    vector<bool> sym(n);
    const function<void(int, int)> dfs_sym = [&](int v, int p) {
        unordered_map<int, vector<int>> ump;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs_sym(c, v);
            ump[hash_root[c]].push_back(c);
        }
        int slot_mid = 1;
        bool is_sym = true;
        for (auto e : ump) {
            if (e.second.size() % 2 == 0) {
                continue;
            } else if (slot_mid >= 1) {
                if (!sym[e.second[0]]) {
                    is_sym = false;
                } else {
                    slot_mid--;
                }
            } else {
                is_sym = false;
            }
        }
        sym[v] = is_sym;
    };
    dfs_sym(0, 0);
    cout << (sym[0] ? "YES" : "NO") << '\n';
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