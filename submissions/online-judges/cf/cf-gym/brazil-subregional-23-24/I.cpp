#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][b[0]]++;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (b[i] == 0) {
            dp[i][0] = 1 + dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        } else {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = 1 + dp[i - 1][0];
        }
    }
    for (int i = 0; i < n; i++) {
        ans += dp[i][1];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}