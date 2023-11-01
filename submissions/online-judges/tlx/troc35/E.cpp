#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

const ll MOD = 998244353;
const int M = 4e5;
ll fc[M + 5], ifc[M + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= M; i++) {
        fc[i] = fc[i - 1] * i % MOD;
    }
    ifc[M] = fpow(fc[M], MOD - 2);
    for (int i = M - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a] * ifc[b] % MOD;
    ret = ret * ifc[a - b] % MOD;
    return ret;
}

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    } else if (n == 2) {
        cout << m << '\n';
        return;
    }
    int bawah = (n - 1) / 2;
    for (int i = 1; i <= bawah; i++) {
        ans = (ans + C(m - i + n - 1, n - 1)) % MOD;
    }
    for (int i = 0; i <= n - 2; i++) {
        ll lmao = (C(m + (n - i) / 2, n - i) - C(m, n - i)) % MOD;
        if (lmao < 0) lmao += MOD;
        ll tmp = C(n, i) * (lmao) % MOD;
        ans = (ans + tmp) % MOD;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init_fac();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}