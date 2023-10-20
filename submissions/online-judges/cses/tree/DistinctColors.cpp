#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans(n);
    const function<void(int, int, unordered_map<int, bool>&)> dfs = [&](int v, int p, unordered_map<int, bool>& ump) -> void {
        ump[c[v]] = true;
        for (auto c : adj[v]) {
            if (c == p) continue;
            unordered_map<int, bool> tmp;
            dfs(c, v, tmp);
            if (tmp.size() > ump.size()) tmp.swap(ump);
            for (auto x : tmp) {
                if (ump.find(x.first) == ump.end()) ump[x.first] = true;
            }
        }
        ans[v] = ump.size();
    };
    unordered_map<int, bool> colors;
    dfs(0, 0, colors);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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