#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;
const int M = 300;

void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void solve() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> dp(n, vector<int>(M * M * 2 + 5));
    const int T = M * M;
    dp[2][ar[2] - ar[1] + T] = 1;
    dp[2][ar[2] + ar[1] + T] = 1;

    for (int i = 3; i < n; i++) {
        for (int j = -T; j <= T; j++) {
            if (j != ar[i]) {
                if (T >= j - ar[i] && j - ar[i] >= -T) add(dp[i][j + T], dp[i - 1][j - ar[i] + T]);
                if (T >= ar[i] - j && ar[i] - j >= -T) add(dp[i][j + T], dp[i - 1][ar[i] - j + T]);
            } else {
                dp[i][j + T] = dp[i - 1][T];
            }
        }
    }

    int ans = 0;
    for (int i = -T; i <= T; i++) {
        add(ans, dp[n - 1][i + T]);
    }
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