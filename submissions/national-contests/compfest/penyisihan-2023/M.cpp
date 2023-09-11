#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n + 5), dp(n + 5), asli(n + 5);
    ll inverse = inv(100);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        asli[i] = p[i];
        p[i] = (p[i] * inverse) % MOD;
    }
    dp[1] = inv(1ll - p[1]);
    vector<vector<ll>> simpan(n + 1, vector<ll>(100));
    for (int i = 0; i < 100; i++) {
        simpan[1][i] = dp[1];
    }
    for (int i = 2; i <= n; i++) {
        ll tmp = (p[i] * p[i]) % MOD;
        tmp = (tmp * simpan[i - 1][asli[i]]) % MOD;
        tmp = (tmp + 1) % MOD;
        tmp = (tmp * inv(1 - p[i])) % MOD;
        if (tmp < 0) tmp += MOD;
        dp[i] = tmp;
        for (int j = 0; j < 100; j++) {
            simpan[i][j] = (simpan[i - 1][j] * j) % MOD;
            simpan[i][j] = (simpan[i][j] * inverse) % MOD;
            simpan[i][j] = (simpan[i][j] + dp[i]) % MOD;
        }
    }
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = (ret + dp[i]) % MOD;
    }
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
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