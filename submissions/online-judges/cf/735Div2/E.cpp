#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> cnt(n), ans(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        edges.emplace_back(a, b);
    }
    for (int i = 0; i < n; i++) {
        cnt[i] = adj[i].size();
    }
    int mn = n;
    for (auto e : edges) {
        int a = e.first, b = e.second;
        mn = min(mn, max(cnt[a], cnt[b]));
    }
    for (int i = mn + 1; i <= n; i++) {
        ans[i] = 0;
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}