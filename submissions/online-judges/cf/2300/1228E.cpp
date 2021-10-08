#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1LL * ret * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct Combi {
    vector<int> fc, ifc;
    int n;
    Combi(int n) : n(n) {
        fc.resize(n + 5), ifc.resize(n + 5);
        init();
    }
    void init() {
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = (1LL * fc[i - 1] * i) % MOD;
        }
        ifc[n] = fpow(fc[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            ifc[i] = (1LL * ifc[i + 1] * (i + 1)) % MOD;
        }
    }
    int cb(int a, int b) {
        if (a < 0 || b < 0 || a < b) {
            return 0;
        }
        int ret = (1LL * fc[a] * ifc[b]) % MOD;
        ret = (1LL * ret * ifc[a - b]) % MOD;
        return ret;
    }
};

ll n, k;

void solve() {
    cin >> n >> k;
    Combi combi = Combi(n);

    vector<int> pa(n + 1), pb(n + 1);
    pa[0] = pb[0] = 1;
    for (int i = 1; i <= n; i++) {
        pa[i] = (1LL * pa[i - 1] * k) % MOD;
        pb[i] = (1LL * pb[i - 1] * (k - 1)) % MOD;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[i][1] = 1;
        for (int j = 2; j <= n; j++) {
            int lol = (pa[i] - pb[i]) % MOD;
            if (lol < 0) lol += MOD;
            int tmp = (1LL * dp[i][j - 1] * lol) % MOD;
            for (int l = 1; l < i; l++) {
                int cur = (1LL * combi.cb(i, l) * pa[i - l]) % MOD;
                cur = (1LL * cur * dp[i - l][j - 1]) % MOD;
                cur = (1LL * cur * fpow(pb[l], (j - 1))) % MOD;
                tmp = (1LL * tmp + cur) % MOD;
            }
            if (tmp < 0) tmp += MOD;
            dp[i][j] = tmp;
        }
    }
    ll ans = dp[n][n] % MOD;
    if (ans < 0) ans += MOD;
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