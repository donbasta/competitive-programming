#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct Combi {
    vector<ll> fc, ifc;
    int n;
    Combi(int n) : n(n) {
        fc.resize(n + 5), ifc.resize(n + 5);
        init();
    }
    void init() {
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = (fc[i - 1] * i) % MOD;
        }
        ifc[n] = fpow(fc[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
        }
    }
    ll cb(ll a, ll b) {
        if (a < 0 || b < 0 || a < b) {
            return 0;
        }
        ll ret = (fc[a] * ifc[b]) % MOD;
        ret = (ret * ifc[a - b]) % MOD;
        return ret;
    }
};

int n, q;

void solve() {
    cin >> n >> q;
    Combi combi = Combi(3 * n);

    ll inv3 = fpow(3, MOD - 2);
    vector<vector<ll>> dp(3 * n + 1, vector<ll>(3));

    dp[0][0] = dp[0][1] = dp[0][2] = n;
    for (int i = 1; i <= 3 * n; i++) {
        ll u = dp[i - 1][0];
        ll v = dp[i - 1][1];
        ll a = (combi.cb(3 * n, i + 1) - u * 2 - v) % MOD;
        if (a < 0) a += MOD;
        a = (a * inv3) % MOD;
        dp[i][0] = a;
        dp[i][1] = (a + u) % MOD;
        dp[i][2] = (a + u + v) % MOD;
    }

    while (q--) {
        int x;
        cin >> x;
        ll ans = dp[x][0];
        ans = (ans + combi.cb(3 * n, x)) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
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