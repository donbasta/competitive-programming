#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    ll mx = *max_element(ve.begin(), ve.end());
    ll ans = mx;
    if (n == 1) {
        cout << mx << '\n';
        return;
    }
    vector<ll> dp(n), ndp(n);
    dp[0] = ve[0];
    dp[1] = ve[1];
    ndp[0] = dp[0];
    ndp[1] = dp[1];
    for (int i = 2; i < n; i++) {
        dp[i] = ve[i];
        dp[i] = max(dp[i], ve[i] + ndp[i - 2]);
        ndp[i] = max(dp[i], ndp[i - 2]);
    }
    ans = max(ans, ndp[n - 2]);
    ans = max(ans, ndp[n - 1]);
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