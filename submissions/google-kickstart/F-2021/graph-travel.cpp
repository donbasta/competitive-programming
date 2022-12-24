#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
ll k;

void solve() {
    cin >> n >> m >> k;
    vector<ll> L(n), R(n), A(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i] >> A[i];
    }
    vector<vector<bool>> adj(n, vector<bool>(n));
    vector<int> jalur;
    for (int i = 0; i < (1 << n); i++) {
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tmp += A[j];
            }
        }
        if (tmp == k) {
            jalur.push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = true;
        adj[y][x] = true;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> dp(1 << n);
        dp[1 << i] = 1;
        for (int j = (1 << i); j < (1 << n); j++) {
            if (!(j & (1 << i))) continue;
            for (int k = 0; k < n; k++) {
                if (j & (1 << k)) continue;
                ll tmp = 0;
                bool sabi = false;
                for (int l = 0; l < n; l++) {
                    if (j & (1 << l)) {
                        tmp += A[l];
                        sabi |= adj[l][k];
                    }
                }
                if ((L[k] <= tmp) && (tmp <= R[k]) && sabi) {
                    dp[j ^ (1 << k)] += dp[j];
                }
            }
        }
        for (auto u : jalur) {
            ans += dp[u];
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