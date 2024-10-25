#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

void el_psy_congroo() {
    string x, y;
    cin >> x >> y;
    int lx = x.length(), ly = y.length();
    vector<int> kx(lx), ky(ly);
    for (int i = lx - 1; i >= 0; i--) {
        if (i == lx - 1 || x[i] == x[i + 1])
            kx[i] = i;
        else
            kx[i] = kx[i + 1];
    }
    for (int i = ly - 1; i >= 0; i--) {
        if (i == ly - 1 || y[i] == y[i + 1])
            ky[i] = i;
        else
            ky[i] = ky[i + 1];
    }

    vector<vector<vector<ll>>> dp(lx, vector<vector<ll>>(ly, vector<ll>(2)));
    for (int i = lx - 1; i >= 0; i--) {
        for (int j = ly - 1; j >= 0; j--) {
            if (i + 1 < lx) {
                if (x[i] != x[i + 1]) dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % MOD;
                if (x[i] != y[j]) dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % MOD;
            }
            if (x[i] != y[j]) dp[i][j][0] = (dp[i][j][0] + ky[j] - j + 1) % MOD;
            if (j + 1 < ly) {
                if (y[j] != y[j + 1]) dp[i][j][1] = (dp[i][j][1] + dp[i][j + 1][1]) % MOD;
                if (x[i] != y[j]) dp[i][j][1] = (dp[i][j][1] + dp[i][j + 1][0]) % MOD;
            }
            if (x[i] != y[j]) dp[i][j][1] = (dp[i][j][1] + kx[i] - i + 1) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < lx; i++) {
        for (int j = 0; j < ly; j++) {
            ans = (ans + dp[i][j][0]) % MOD;
            ans = (ans + dp[i][j][1]) % MOD;
        }
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