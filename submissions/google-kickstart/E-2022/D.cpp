#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

ll floor(ll a, ll b) {
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b;
    return (a / b) - 1;
}

function<ll(ll)> createFunc(char op, ll val) {
    function<ll(ll)> haha = [=](ll x) -> ll {
        if (op == '+') {
            return x + val;
        }
        if (op == '-') {
            return x - val;
        }
        if (op == '*') {
            return x * val;
        }
        return floor(x, val);
    };
    return haha;
}

void solve() {
    int n, m, p, ar, ac;
    cin >> n >> p >> m >> ar >> ac;
    --ar, --ac;
    vector<function<ll(ll)>> lol;
    for (int i = 0; i < 4; i++) {
        char op;
        ll val;
        cin >> op >> val;
        lol.emplace_back(createFunc(op, val));
    }
    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<vector<ll>> cost(n, vector<ll>(n));
    vis[ar][ac] = true;
    for (int i = 0; i < m; i++) {
        vector<vector<ll>> tcost(n, vector<ll>(n));
        vector<vector<bool>> tvis(n, vector<bool>(n));
        tvis = vis;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (!vis[r][c]) continue;
                if (r > 0) {
                    if (tvis[r - 1][c])
                        tcost[r - 1][c] = max(lol[0](cost[r][c]), cost[r - 1][c]);
                    else {
                        tcost[r - 1][c] = lol[0](cost[r][c]);
                        tvis[r - 1][c] = true;
                    }
                }
                if (c < n - 1) {
                    if (tvis[r][c + 1])
                        tcost[r][c + 1] = max(lol[1](cost[r][c]), cost[r][c + 1]);
                    else {
                        tcost[r][c + 1] = lol[1](cost[r][c]);
                        tvis[r][c + 1] = true;
                    }
                }
                if (c > 0) {
                    if (tvis[r][c - 1])
                        tcost[r][c - 1] = max(lol[2](cost[r][c]), cost[r][c - 1]);
                    else {
                        tcost[r][c - 1] = lol[2](cost[r][c]);
                        tvis[r][c - 1] = true;
                    }
                }
                if (r < n - 1) {
                    if (tvis[r + 1][c])
                        tcost[r + 1][c] = max(lol[3](cost[r][c]), cost[r + 1][c]);
                    else {
                        tcost[r + 1][c] = lol[3](cost[r][c]);
                        tvis[r + 1][c] = true;
                    }
                }
            }
        }
        cost = tcost;
        vis = tvis;
    }
    ll ans = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) {
                ans = max(ans, cost[i][j]);
            }
        }
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
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
