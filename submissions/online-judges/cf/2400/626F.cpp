#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 200;
const int K = 1000;

inline void add(int& a, int b) {
    a = (1LL * a + b) % MOD;
}

int dp[N + 5][N + 5][K + 5];
int n, kk;
int ar[N + 5];

void solve() {
    cin >> n >> kk;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    sort (ar + 1, ar + n + 1);
    dp[1][1][0] = 1;
    dp[1][0][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= kk; k++) {
                int k1 = k - (j - 1) * (ar[i] - ar[i - 1]);
                int k2 = k - (j) * (ar[i] - ar[i - 1]);
                int k3 = k - (j + 1) * (ar[i] - ar[i - 1]);
                if (j > 0 && k1 >= 0) add(dp[i][j][k], dp[i - 1][j - 1][k1] % MOD);
                if (k2 >= 0) add(dp[i][j][k], 1LL * (j + 1) * dp[i - 1][j][k2] % MOD);
                if (k3 >= 0) add(dp[i][j][k], 1LL * (j + 1) * dp[i - 1][j + 1][k3] % MOD);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= kk; i++) {
        ans = (1LL * ans + dp[n][0][i]) % MOD;
    }
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