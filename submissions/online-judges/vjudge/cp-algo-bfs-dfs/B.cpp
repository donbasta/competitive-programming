#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cur = -1;
    for (auto e : adj) {
        if (e.second.size() == 1) {
            cur = e.first;
            break;
        }
    }
    vector<int> ans;
    ans.push_back(cur);
    int prv = cur;
    cur = adj[cur][0];
    while (adj[cur].size() == 2) {
        ans.push_back(cur);
        for (auto c : adj[cur]) {
            if (c != prv) {
                prv = cur;
                cur = c;
                break;
            }
        }
    }
    ans.push_back(cur);
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
    return;
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