#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll MOD;
const int Q = 1e3;
const ll MX = 1e6;

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

struct Combi {
    vector<ll> fc, ifc;
    void init(int n) {
        fc.resize(n + 5), ifc.resize(n + 5);
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
} combi;

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

    combi.init(q + 5);
    vector<ll> dp(q + 5);

    if (p > 1) {
        ll tmp = calc_geom_seq(p, n);
        tmp = (tmp - 1) % MOD;
        if (tmp < 0) tmp += MOD;
        dp[0] = tmp;
    } else if (p == 1) {
        dp[0] = (n % MOD);
    }

    for (int i = 1; i <= q; i++) {
        ll tmp = 0;
        for (int j = 0; j < i; j++) {
            ll xx = (p * combi.cb(i - 1, j)) % MOD;
            xx = (xx * dp[i - 1 - j]) % MOD;
            tmp = (tmp + xx) % MOD;
        }
        tmp = (tmp + p) % MOD;
        ll lol = (fpow(p, n + 1) * fpow(n + 1, i)) % MOD;
        tmp = (tmp - lol) % MOD;
        dp[i] = tmp;
    }

    ll ret = dp[q] % MOD;
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
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