#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll n, s, m, l;
    cin >> n >> s >> m >> l;
    vector<ll> dp(n + 16, INF);
    dp[0] = 0;
    for (int i = 1; i <= n + 15; i++) {
        if (i >= 6)
            dp[i] = min(dp[i], dp[i - 6] + s);
        if (i >= 8)
            dp[i] = min(dp[i], dp[i - 8] + m);
        if (i >= 12)
            dp[i] = min(dp[i], dp[i - 12] + l);
    }
    ll ans = dp[n];
    for (int i = n + 1; i <= n + 15; i++) {
        ans = min(ans, dp[i]);
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