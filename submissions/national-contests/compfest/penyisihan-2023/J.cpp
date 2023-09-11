#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 4e18;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) dp[i][i] = x;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            // dp[i][i + len - 1] = ...
            for (int k = i; k < i + len - 1; k++) {
                dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][k] + dp[k + 1][i + len - 1]);
            }
            int top = c[i];
            int last = i;
            ll cnt = 1;
            ll cur = 0;
            for (int k = i + 1; k <= i + len - 1; k++) {
                if (c[k] == top) {
                    if (cnt == 0) {
                        cur += dp[last + 1][k - 1];
                    }
                    last = k;
                    cnt++;
                } else {
                    cur += cnt * y;
                    cnt = 0;
                }
            }
            if (last + 1 <= i + len - 1) cur += dp[last + 1][i + len - 1];
            cur += x;
            dp[i][i + len - 1] = min(dp[i][i + len - 1], cur);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    cout << dp[0][n - 1] << '\n';
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