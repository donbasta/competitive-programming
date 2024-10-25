
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int N = 1e6;

ll fc[N + 1], ifc[N + 1], ipw[N + 1];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void init() {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = inv(fc[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
    ll i2 = inv(2);
    ipw[0] = 1;
    for (int i = 1; i <= N; i++) {
        ipw[i] = (ipw[i - 1] * i2) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < 0 || a < b || b < 0) return 0;
    ll ret = ((fc[a] * ifc[a - b]) % MOD) * ifc[b] % MOD;
    return ret;
}

void el_psy_congroo() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n == m) {
        ll ret = (1ll * k * n) % MOD;
        cout << ret << '\n';
        return;
    }

    ll ans = 0;
    for (int i = m; i >= 0; i--) {
        ll tmp = (C(n - 1 - i, n - m - 1) * i) % MOD;
        tmp = (tmp * ipw[n - i]) % MOD;
        ans = (ans + tmp) % MOD;
    }
    ans = (ans * k) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}