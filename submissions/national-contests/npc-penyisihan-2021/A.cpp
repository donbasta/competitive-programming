#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000;
const ll MOD = 1e9 + 7;

ll dp[N + 5][N + 5];

void init() {
    for (int i = 0; i <= N; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - j][j]) % MOD;
            }
        }
    }
}

void solve() {
    int m, n;
    cin >> m >> n;
    ll ans = dp[m][n];
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}