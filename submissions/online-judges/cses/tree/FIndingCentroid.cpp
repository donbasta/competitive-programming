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
    vector<int> cnt(n);
    const function<void(int, int)> dfs_size = [&](int v, int p) {
        cnt[v]++;
        for (auto c : adj[v]) {
            if (c == p) continue;
            dfs_size(c, v);
            cnt[v] += cnt[c];
        }
    };
    dfs_size(0, 0);
    const function<int(int, int)> get_centroid = [&](int v, int p) {
        for (auto c : adj[v]) {
            if (c == p) continue;
            if (cnt[c] > (n / 2)) {
                return get_centroid(c, v);
            }
        }
        return v;
    };
    cout << (get_centroid(0, 0) + 1) << '\n';
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