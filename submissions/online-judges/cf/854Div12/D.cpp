#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n + 5), cold(k + 5), hot(k + 5);
    for (int i = 0; i < n; i++) {
        cin >> ar[i + 1];
        --ar[i + 1];
    }
    for (int i = 0; i < k; i++) {
        cin >> cold[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> hot[i];
    }
    if (n == 1) {
        cout << cold[ar[1]] << '\n';
        return;
    }
    const auto now = [&](int a, int b) {
        if (b == 0) return cold[ar[a]];
        if (ar[a] == ar[b]) return hot[ar[a]];
        return cold[ar[a]];
    };
    vector<ll> bruh(n + 5, INF);
    bruh[1] = cold[ar[1]];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[i][0] = (dp[i - 1][0] + now(i, i - 1));
        if (i + 1 <= n) bruh[i + 1] = min(bruh[i + 1], dp[i][0] + cold[ar[i + 1]]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (i - 1 == j) {
                dp[i][i - 1] = bruh[i];
                bruh[i + 1] = min(bruh[i + 1], dp[i][i - 1] + now(i + 1, i - 1));
            } else if (i + 1 == j) {
                dp[j - 1][j] = bruh[j];
                bruh[j + 1] = min(bruh[j + 1], dp[j - 1][j] + now(j + 1, j - 1));
            } else if (i > j) {
                dp[i][j] = dp[i - 1][j] + now(i, i - 1);
                bruh[i + 1] = min(bruh[i + 1], dp[i][j] + now(i + 1, j));
            } else if (i < j) {
                dp[i][j] = dp[i][j - 1] + now(j, j - 1);
                bruh[j + 1] = min(bruh[j + 1], dp[i][j] + now(j + 1, i));
            }
        }
    }
    ll ans = INF;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    //     }
    // }
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}