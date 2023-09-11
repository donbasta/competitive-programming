#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> cost;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[make_pair(a, b)] = c;
        tot += c;
    }
    int A = 0;
    int prv = 0;
    int now = adj[0][0];
    if (cost.find(make_pair(prv, now)) == cost.end()) {
        A += cost[make_pair(now, prv)];
    }
    for (int k = 0; k < n - 1; k++) {
        for (auto e : adj[now]) {
            if (e == prv) continue;
            if (cost.find(make_pair(now, e)) == cost.end()) {
                A += cost[make_pair(e, now)];
            }
            prv = now;
            now = e;
            break;
        }
    }
    cout << min(A, tot - A) << '\n';
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