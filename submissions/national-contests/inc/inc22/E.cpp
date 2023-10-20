#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 31;

struct Trie {
    struct Node {
        Node* child[2];
        Node() { child[0] = child[1] = nullptr; }
    };
    Node* head;
    bool empty;
    Trie() : empty(true) { head = new Node(); }
    void insert(int val) {
        empty = false;
        Node* cur = head;
        for (int i = B; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (cur->child[v] == nullptr) cur->child[v] = new Node();
            cur = cur->child[v];
        }
    }
    int get_min_xor(int val) {
        Node* cur = head;
        int ret = 0;
        for (int i = B; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (cur->child[v]) {
                cur = cur->child[v];
            } else {
                cur = cur->child[v ^ 1];
                ret += (1 << i);
            }
        }
        return ret;
    }
    int get_max_xor(int val) {
        Node* cur = head;
        int ret = 0;
        for (int i = B; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (cur->child[v ^ 1]) {
                cur = cur->child[v ^ 1];
                ret += (1 << i);
            } else {
                cur = cur->child[v];
            }
        }
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> dis(n);
    const function<void(int, int)> dfs = [&](int v, int p) -> void {
        for (auto c : adj[v]) {
            if (c.first == p) continue;
            dis[c.first] = dis[v] ^ c.second;
            dfs(c.first, v);
        }
    };
    dfs(0, 0);
    Trie t;
    t.insert(0);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 1; i < n; i++) {
        mn = min(mn, t.get_min_xor(dis[i]));
        mx = max(mx, t.get_max_xor(dis[i]));
        t.insert(dis[i]);
    }
    cout << mn << ' ' << mx << '\n';
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
