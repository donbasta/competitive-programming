#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

int n, S;
int dp[2][N + 5][N * N + 5];
int a[N + 5], b[N + 5];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        S += b[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1][a[1]] = b[1];
    dp[1][0][0] = 0;
    for (int i = 2; i <= n; i++) {
        int ii = i & 1;
        for (int j = 0; j <= min(i, n); j++) {
            for (int k = 0; k <= N * i; k++) {
                dp[ii][j][k] = max (dp[ii][j][k], dp[ii ^ 1][j][k]);
                if (j > 0 && k >= a[i] && dp[ii ^ 1][j - 1][k - a[i]] >= 0) {
                    dp[ii][j][k] = max (dp[ii][j][k], dp[ii ^ 1][j - 1][k - a[i]] + b[i]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = -1;
        for (int j = 0; j <= n * N; j++) {
            if (dp[n & 1][i][j] >= 0) {
                ans = max(ans, min(j * 2, dp[n & 1][i][j] + S));
            }
        }
        cout << ((double) ans) / 2.0 << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(10);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}