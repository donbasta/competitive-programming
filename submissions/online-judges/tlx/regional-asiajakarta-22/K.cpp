#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return d;
}

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    ll X = 1;
    for (int i = 0; i < n; i++) {
        X = (X * ve[i]) % MOD;
    }
    ll T = 1;
    ll k2 = fpow(2, k, n);
    ll k22 = (k2 + n - 2) % n;
    if (k22 < 0) k22 += n;
    for (int i = 0; i <= k22; i++) {
        T = (T * ve[i]) % MOD;
    }
    // bruh = (2^k + n - 2)/n mod (MOD - 1)
    ll LHS = (fpow(2, k, MOD - 1) + n - 2 - k22) % (MOD - 1);
    ll GCD = __gcd(n, MOD - 1);
    LHS /= GCD;
    ll invert;
    LHS = (LHS * invert) % MOD;

    ll XX = fpow(X, bruh, MOD);
    T = (T * XX) % MOD;

    ll idx = k2;
    ll U = 1;
    for (int i = 0; i < n; i++) {
        U = (U * ve[idx]) % MOD;
        idx = (idx + 1) % n;
    }
    vector<ll> ret(n);
    ret[0] = (T * fpow(U, MOD - 2, MOD)) % MOD;

    idx = k2;
    for (int i = 1; i < n; i++) {
        ret[i] = (ret[i - 1] * ve[idx]) % MOD;
        ret[i] = (ret[i] * fpow(ve[i - 1], MOD - 2, MOD)) % MOD;
    }
    for (int i = 0; i < n; i++) {
        cout << ve[i] << ' ';
    }
    cout << '\n';
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