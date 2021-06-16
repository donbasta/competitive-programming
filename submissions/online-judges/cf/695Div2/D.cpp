#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 5e3;

int n, k, q;
ll a[N + 10], c[N + 10];
ll dp[N+ 10][N + 10];

void solve() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            c[i] = (c[i] + dp[i][j] * dp[i][k - j]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + a[i] * c[i]) % MOD;
    }
    while (q--) {
        int i;
        ll x;
        cin >> i >> x;
        ans = (ans - a[i] * c[i]) % MOD;
        a[i] = x;
        ans = (ans + a[i] * c[i]) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
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