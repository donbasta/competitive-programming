#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int L = 250;
const int N = 3e4;

int dp[N + 5][2 * L + 5];
int gem[N + 5];
int n, d;

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        gem[p]++;
    }
    memset(dp, -1, sizeof(dp));
    int offset = 250 - d;
    dp[d][d + offset] = gem[d];
    for (int i = d + 1; i <= N; i++) {
        for (int j = d - L; j <= d + L; j++) {
            if (j <= 0) continue;
            if (i >= j && j > 1 && dp[i - j][j - 1 + offset] >= 0)
                dp[i][j + offset] = max(dp[i - j][j - 1 + offset] + gem[i], dp[i][j + offset]);
            if (i >= j && j < d + L && dp[i - j][j + 1 + offset] >= 0)
                dp[i][j + offset] = max(dp[i - j][j + 1 + offset] + gem[i], dp[i][j + offset]);
            if (i >= j && dp[i - j][j + offset] >= 0)
                dp[i][j + offset] = max(dp[i - j][j + offset] + gem[i], dp[i][j + offset]);
        }
    }
    int ans = 0;
    for (int i = d; i <= N; i++) {
        for (int j = d - L; j <= d + L; j++) {
            if (j <= 0) continue;
            ans = max(ans, dp[i][j + offset]);
        }
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