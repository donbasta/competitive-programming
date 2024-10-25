#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int I, S, L, U;
    cin >> I >> S >> L >> U;
    vector<vector<pair<int, int>>> adj(I);
    vector<pair<int, int>> edges;
    for (int ii = 0; ii < S; ii++) {
        int i, j, l;
        cin >> i >> j >> l;
        edges.emplace_back(i, j);
        adj[i].emplace_back(j, l);
        adj[j].emplace_back(i, l);
    }
    vector<int> dis(I, INF);
    set<pair<int, int>> se;
    dis[0] = 0;
    se.emplace(0, 0);
    while (!se.empty()) {
        auto now = *se.begin();
        int v = now.second, dv = now.first;
        se.erase(se.begin());
        for (auto c : adj[v]) {
            if (dis[c.first] > dis[v] + c.second) {
                se.erase(make_pair(dis[c.first], c.first));
                dis[c.first] = dis[v] + c.second;
                se.emplace(dis[c.first], c.first);
            }
        }
    }
    // for (int i = 0; i < I; i++) {
    //     cerr << i << ' ' << dis[i] << '\n';
    // }
    int ans = 0;
    for (int i = 0; i < S; i++) {
        int u = edges[i].first, v = edges[i].second;
        ans += (2 * min(dis[u], dis[v]) + 1 <= U);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}