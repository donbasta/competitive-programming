#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int fpar(int x) {
        return ((x == par[x] ? x : par[x] = fpar(par[x])));
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        par[x] = y;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n), in(n);
    vector<vector<int>> from(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        dsu.merge(a, b);
        from[a].push_back(b);
        in[b]++;
    }
    vector<long long> dp(n);
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            Q.push(i);
            dp[i] = h[i];
        }
    }
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for (auto c : from[now]) {
            ll earliest;
            if (h[c] >= h[now]) {
                earliest = dp[now] + (h[c] - h[now]);
            } else {
                earliest = dp[now] + (k + h[c] - h[now]);
            }
            dp[c] = max(dp[c], earliest);
            --in[c];
            if (in[c] == 0) {
                Q.push(c);
            }
        }
    }
    vector<ll> mn(n, INF), mx(n, -INF);
    for (int i = 0; i < n; i++) {
        int pi = dsu.fpar(i);
        mn[pi] = min(mn[pi], dp[i]);
        mx[pi] = max(mx[pi], dp[i]);
    }
    vector<pair<int, int>> itv;
    for (int i = 0; i < n; i++) {
        if (mn[i] == INF) continue;
        itv.emplace_back(mn[i], mx[i]);
    }
    // ll lo = 0, hi = INF;
    // while (lo <= hi) {
    // }
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