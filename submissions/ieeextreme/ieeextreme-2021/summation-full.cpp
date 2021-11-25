#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll MOD;
const int Q = 1e3;
const int MX = 1e7;

ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

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

    combi.init(Q + 5);
    vector<ll> dp(q + 5);
    ll pn1 = fpow(p, n + 1);
    ll pn = fpow(p, n);

    ll invp, lol;
    ll fpb = extended_euclidean(p - 1, m, invp, lol);
    if (fpb > 1) {
        cout << -1 << '\n';
        return;
    }

    ll geo = (fpow(p, n + 1) - p) % MOD;
    geo = (geo * invp) % MOD;
    if (geo < 0) geo += MOD;

    if (q == 0) {
        cout << geo << '\n';
        return;
    }

    vector<ll> npw(q + 5);
    ll tmp = 1;
    for (int i = 0; i < q + 5; i++) {
        npw[i] = tmp;
        tmp = (tmp * n) % MOD;
    }

    for (int i = 1; i <= q; i++) {
        ll tmp = pn1 * npw[i];
        for (int j = i - 1; j >= 1; j--) {
            ll lolz = (combi.cb(i, i - j) * p) * MOD;
            ll lolz2 = (dp[j] - pn * npw[j]) % MOD;
            lolz = (lolz * lolz2) % MOD;
            tmp = (tmp - lolz) % MOD;
        }
        tmp = (tmp - geo) % MOD;
        dp[i] = (tmp * invp) % MOD;
    }

    ll ans = dp[q] % MOD;
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