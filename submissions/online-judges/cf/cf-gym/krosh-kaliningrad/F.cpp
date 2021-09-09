#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2000;
const int mod = 1e9 + 7;

int dp[N + 5][N + 5][2];
int dp2[N + 5][N + 5];
int sum[N + 5], sum2[N + 5];
int m, n;

void solve() {
    cin >> m >> n;
    if (m == 1 && n == 1) {
        if (m == 1) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }
    if (n == 2) {
        cout << 2 << '\n';
        return;
    }
    dp[0][0][0] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= 1 && j < n - 1) dp[i][j][0] += dp[i - 1][j - 1][0];
            if (j + 1 < n) dp[i][j][0] += dp[i - 1][j + 1][0];
            dp[i][j][0] %= mod;
            if (j >= 1) dp[i][j][1] += dp[i - 1][j - 1][1];
            if (j + 1 < n) dp[i][j][1] += dp[i - 1][j + 1][1];
            if (j == n - 1) {
                dp[i][j][1] += dp[i - 1][j - 1][0];
            }
            dp[i][j][1] %= mod;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i] = (sum[i] + dp[i][j][1]) % mod;
        }
    }

    sum2[0] = 1;
    dp2[0][2] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 2; j < n; j++) {
            dp2[i][j] += dp2[i - 1][j - 1];
            dp2[i][j] += dp2[i - 1][j + 1];
            dp2[i][j] %= mod;
            sum2[i] = (sum2[i] + dp2[i][j]) % mod;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ll ki = ((i >= 2) ? sum2[i - 2] : 1);
        ll tmp = (sum[m - i] * ki) % mod;
        ans = (ans + tmp) % mod;
    }
    ans = (ans * 2) % mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}