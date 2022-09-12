#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << '\n';
        return;
    }
    int r = -1;
    ll cm = m;
    while (cm) {
        cm >>= 1;
        r++;
    }
    if (n > r + 1) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<ll>> dp(r + 5, vector<ll>(r + 5));
    for (int i = 0; i <= r; i++) {
        dp[i][1] = fpow(2LL, i);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j <= r; j++) {
            for (int k = i - 2; k < j; k++) {
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % MOD;
            }
            dp[j][i] = (dp[j][i] * fpow(2LL, j)) % MOD;
        }
    }
    // cerr << "lol\n";
    ll ans = 0;
    for (int i = max(0LL, n - 2); i < r; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    // ll ans = r ? dp[r - 1][n] : 0;
    // cerr << ans << '\n';
    // for (int i = 0; i <= 10; i++) {
    //     for (int j = 1; j <= 2; j++) {
    //         cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
    //     }
    // }
    ll sisa = (m + 1 + MOD - fpow(2LL, r)) % MOD;
    ll tmp = 0;
    for (int i = max(0LL, n - 2); i < r; i++) {
        tmp = (tmp + dp[i][n - 1]) % MOD;
    }
    ll add = (sisa * tmp) % MOD;
    ans = (ans + add) % MOD;
    if (ans < 0) ans += MOD;
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