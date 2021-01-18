#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200;
const int M = 30;

int n, k;
int a[N + 5], b[N + 5];
int dp[2][N + 5][N * M + 5];

int vp(ll n, ll p) {
    int ret = 0;
    while (n % p == 0) ret++, n /= p;
    return ret;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = vp(x, 2);
        b[i] = vp(x, 5);
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1][b[1]] = a[1];
    dp[1][0][0] = 0;
    for (int i = 2; i <= n; i++) {
        int ii = i & 1;
        for (int j = 0; j <= min(k, i); j++) {
            for (int l = 0; l <= i * M; l++) {
                dp[ii][j][l] = max(dp[ii][j][l], dp[ii ^ 1][j][l]);
                if (j > 0 && l >= b[i] && dp[ii ^ 1][j - 1][l - b[i]] >= 0) {
                    dp[ii][j][l] = max(dp[ii][j][l], dp[ii ^ 1][j - 1][l - b[i]] + a[i]);    
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= n * M; i++) {
        ans = max (ans, min(i, dp[n & 1][k][i]));
    }
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

// 50 -> 1, 2
// 4 -> 2, 0
// 20 -> 2, 1