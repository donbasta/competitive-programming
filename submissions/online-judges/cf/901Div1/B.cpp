#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    int x = (a | b | m);
    int y = (c | d);
    if ((x | y) != x) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ve(7);
    ve[0] = b & (b ^ (a | m));
    ve[1] = a & (a ^ (b | m));
    ve[2] = m & (m ^ (a | b));
    ve[3] = b ^ (b | (a & m));
    ve[4] = a ^ (a | (b & m));
    ve[5] = m ^ (m | (a & b));
    ve[6] = a & b & m;

    int mx_mask = (1 << 7);
    int M = (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6);
    int A = (1 << 1) + (1 << 3) + (1 << 5) + (1 << 6);
    int B = (1 << 0) + (1 << 4) + (1 << 5) + (1 << 6);
    vector<int> CC, DD;

    for (int i = 0; i < mx_mask; i++) {
        int tmp = 0;
        for (int j = 0; j < 7; j++) {
            if ((i >> j) & 1) tmp += ve[j];
        }
        if (tmp == c) {
            CC.emplace_back(i);
        }
        if (tmp == d) {
            DD.emplace_back(i);
        }
    }
    if (CC.empty() || DD.empty()) {
        cout << -1 << '\n';
        return;
    }

    auto F = [&](int aa, int bb) {
        return (aa << 7) + bb;
    };
    vector<vector<int>> adj(1 << 14);
    for (int i = 0; i < mx_mask; i++) {
        for (int j = 0; j < mx_mask; j++) {
            adj[F(i, j)].emplace_back(F(i & j, j));
            adj[F(i, j)].emplace_back(F(i | j, j));
            adj[F(i, j)].emplace_back(F(i, i ^ j));
            adj[F(i, j)].emplace_back(F(i, j ^ M));
        }
    }
    queue<int> Q;
    Q.emplace(F(A, B));
    vector<int> dis(1 << 14, INF);
    vector<bool> vis(1 << 14, false);
    dis[F(A, B)] = 0;
    vis[F(A, B)] = true;
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : adj[now]) {
            if (vis[c]) continue;
            vis[c] = true;
            dis[c] = min(dis[c], dis[now] + 1);
            Q.emplace(c);
        }
    }
    int ans = INT_MAX;
    for (auto cc : CC) {
        for (auto dd : DD) {
            ans = min(ans, dis[F(cc, dd)]);
        }
    }
    if (ans == INF) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
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