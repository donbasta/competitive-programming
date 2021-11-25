#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int MX = 500;

ll fc[MX + 5], ifc[MX + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= MX; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[MX] = fpow(fc[MX], MOD - 2);
    for (int i = MX - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    ll ret = (fc[a] * ifc[b]) % MOD;
    ret = (ret * ifc[a - b]) % MOD;
    return ret;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1));

    for (int j = 1; j <= x; j++) {
        dp[2][j] = j;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j < i) {
                dp[i][j] = fpow(j, i);
                continue;
            }
            ll tmp = fpow(i - 1, i);
            for (int k = 1; k <= i; k++) {
                ll lol = (dp[k][j - i + 1] * C(i, k)) % MOD;
                lol = (lol * fpow(i - 1, i - k)) % MOD;
                tmp = (tmp + lol) % MOD;
            }
            dp[i][j] = tmp;
        }
    }

    ll ans = dp[n][x] % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}