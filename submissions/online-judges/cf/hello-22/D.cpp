#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<ll>> cost(n * 2, vector<ll>(n * 2));
    ll ans = 0;
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n * 2; j++) {
            cin >> cost[i][j];
            if (i >= n && j >= n) {
                ans += cost[i][j];
            }
        }
    }
    ll add = INF;
    add = min(add, cost[0][n]);
    add = min(add, cost[0][2 * n - 1]);
    add = min(add, cost[n - 1][n]);
    add = min(add, cost[n - 1][2 * n - 1]);
    add = min(add, cost[n][0]);
    add = min(add, cost[n][n - 1]);
    add = min(add, cost[2 * n - 1][0]);
    add = min(add, cost[2 * n - 1][n - 1]);

    ll ret = (ans + add);
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}