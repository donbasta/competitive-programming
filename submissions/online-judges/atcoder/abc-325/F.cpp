#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int M = 1e3;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> d(n);
    vector<ll> l(2), c(2), k(2);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> l[i] >> c[i] >> k[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(M + 1, INF));

    auto calc = [&](ll tot, ll l1, ll l2, ll c1) -> ll {
        ll sisa = tot - l1 * c1;
        if (sisa < 0) return 0ll;
        return (sisa + l2 - 1) / l2;
    };
    for (int i = 0; i <= k[0]; i++) {
        dp[0][i] = calc(d[0], l[0], l[1], i);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k[0]; j++) {
            for (int x = 0; x <= j; x++) {
                if (dp[i - 1][j - x] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - x] + calc(d[i], l[0], l[1], x));
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k[0]; i++) {
        if (dp[n - 1][i] == INF) continue;
        if (dp[n - 1][i] > k[1]) continue;
        ans = min(ans, c[0] * i + c[1] * dp[n - 1][i]);
    }
    if (ans == INF) {
        cout << -1 << '\n';
        return;
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