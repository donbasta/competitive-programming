#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll MOD;
const int Q = 1e3;
const int MX = 1e7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll calc_geom_seq(ll r, ll pw) {
    if (pw == 0) {
        return 1;
    }
    if (pw == 1) {
        return (1 + r) % MOD;
    }
    ll rec = calc_geom_seq((r * r) % MOD, pw / 2);
    rec = (rec * (1 + r)) % MOD;
    if (pw % 2 == 0) {
        rec = (rec - fpow(r, pw + 1)) % MOD;
    }
    if (rec < 0) rec += MOD;
    return rec;
}

void solve() {
    ll p, q, n, m;
    cin >> p >> q >> n >> m;
    MOD = m;

    if (n <= MX) {
        ll ret = 0;
        ll ppow = 1;
        for (int i = 1; i <= n; i++) {
            ppow = (ppow * p) % m;
            ll tmp = (fpow(i, q) * ppow) % m;
            ret = (ret + tmp) % m;
        }
        ret %= m;
        if (ret < 0) ret += m;
        cout << ret << '\n';
        return;
    }

    if (m <= MX) {
        vector<ll> dp(m + 1);
        ll pw = p;
        for (int i = 1; i <= m; i++) {
            ll tmp = (pw * fpow(i, q)) % MOD;
            dp[i] = (dp[i - 1] + tmp) % MOD;
            pw = (pw * p) % MOD;
        }

        ll rem = n % m;
        ll quot = n / m;
        ll ans = 0;
        ll pm = fpow(p, m);
        ans = (dp[m] * calc_geom_seq(pm, quot - 1)) % MOD;
        ans = (ans + dp[rem] * fpow(p, m * quot)) % MOD;

        if (ans < 0) ans += MOD;
        cout << ans << '\n';
        return;
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