#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(n / k + 5));
    int fac = 1;
    for (int i = 1; i <= k; i++) {
        fac = (1ll * fac * i) % mod;
    }
    int pw = 1;
    for (int i = 0; i < k; i++) {
        dp[i][0] = pw;
        pw = (1ll * pw * k) % mod;
    }
    for (int i = k; i <= n; i++) {
        for (int j = 0; j <= i / k; j++) {
            int lol = (dp[i - 1][j] - (i >= k ? dp[i - k][j] : 0)) % mod;
            dp[i][j] = (1ll * lol * k) % mod;
            if (i >= k && j >= 1) {
                dp[i][j] = (1ll * fac * dp[i - k][j - 1] + dp[i][j]) % mod;
                dp[i][j] = (dp[i][j] - dp[i - 1][j + 1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - k][j + 1]) % mod;
            }
        }
    }
    for (int i = k; i <= n; i++) {
        for (int j = 0; j <= n / k; j++) {
            cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n / k; i++) {
        ans = (1ll * i * dp[n][i] + ans) % mod;
    }
    if (ans < 0) ans += mod;
    cout << ans << '\n';
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