#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, d;
    cin >> n >> d;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<ld>> dp(1 << n, vector<ld>(d + 1));
    vector<ll> sum(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            sum[i] += w[j];
        }
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int j = 2; j <= d; j++) {
            ld tmp = sum[mask];
            dp[mask][j] = (tmp * tmp / j) * (j - 1);
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                int now = mask ^ sub;
                ld tot_now = sum[now], tot_sub = sum[sub];
                ld lmao = (tot_now * tot_now / j * (j - 1)) - (tot_now / j * 2 * tot_sub) + dp[sub][j - 1] + (tot_sub * tot_sub / (j * (j - 1)));
                dp[mask][j] = min(dp[mask][j], lmao);
            }
        }
    }
    cout << fixed << setprecision(16);
    cout << (dp[(1 << n) - 1][d] / d) << '\n';
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