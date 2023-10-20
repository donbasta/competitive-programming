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
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (n == 2) {
        cout << 1 << ' ' << 2 << '\n';
        return;
    }

    const int K = 16;
    const int M = 2e6;

    map<vector<int>, int> hashes;
    vector<pair<int, vector<int>>> hash_to_sz(M + 5);
    hashes[{}] = 0, hash_to_sz[0] = make_pair(1, vector<int>{});
    hashes[{0}] = 1, hash_to_sz[1] = make_pair(2, vector<int>{0});
    hashes[{0, 0}] = 2, hash_to_sz[2] = make_pair(3, vector<int>{0, 0});
    hashes[{1}] = 3, hash_to_sz[3] = make_pair(3, vector<int>{1});

    int avail = 4;
    vector<int> last(K);
    last[1] = 0, last[2] = 1, last[3] = 3;
    const function<void(int)> generate_tree = [&](int sz) {
        set<vector<int>> trees;
        vector<int> tmp;
        const function<void(int, int)> rec = [&](int idx, int need) {
            if (need == hash_to_sz[idx].first) {
                tmp.push_back(idx);
                trees.insert(tmp);
                tmp.pop_back();
                return;
            }
            tmp.push_back(idx);
            int need_now = need - hash_to_sz[idx].first;
            for (int i = min(idx, last[need_now]); i >= 0; i--) {
                rec(i, need_now);
            }
            tmp.pop_back();
        };
        for (int i = avail - 1; i >= 0; i--) {
            rec(i, sz - 1);
        }
        for (auto e : trees) {
            hashes[e] = avail;
            hash_to_sz[avail] = make_pair(sz, e);
            avail++;
        }
        last[sz] = avail - 1;
    };

    for (int i = 4; i < K; i++) {
        generate_tree(i);
    }

    set<int> H;
    vector<int> hash_root(n, -1), sz(n);
    const function<void(int, int)> dfs_size = [&](int v, int p) {
        sz[v] += 1;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs_size(c, v);
            sz[v] += sz[c];
        }
    };
    dfs_size(0, 0);
    const function<void(int, int)> dfs = [&](int v, int p) {
        vector<int> tmp;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs(c, v);
            if (sz[v] < K) {
                tmp.push_back(hash_root[c]);
            }
        }
        if (sz[v] < K) {
            sort(tmp.begin(), tmp.end(), greater<>());
            H.insert(hashes[tmp]);
            hash_root[v] = hashes[tmp];
        }
    };
    dfs(0, 0);
    int cari = 0;
    while (H.count(cari)) cari++;
    int base_sz = hash_to_sz[cari].first;

    vector<pair<int, int>> edges;
    const function<void(int, int, const vector<int>&)> reconstruct_tree = [&](int s, int e, const vector<int>& children_hashes) {
        int child_root = s + 1;
        for (auto c : children_hashes) {
            edges.emplace_back(s, child_root);
            auto lmao = hash_to_sz[c];
            reconstruct_tree(child_root, child_root + lmao.first - 1, lmao.second);
            child_root += lmao.first;
        }
    };
    reconstruct_tree(1 + n - base_sz, n, hash_to_sz[cari].second);
    int now = 1 + n - base_sz, nx = n - base_sz;
    while (nx >= 1) {
        edges.emplace_back(now, nx);
        now = nx;
        nx--;
    }
    for (auto e : edges) {
        cout << e.first << ' ' << e.second << '\n';
    }
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
