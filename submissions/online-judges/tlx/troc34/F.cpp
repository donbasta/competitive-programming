#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
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

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;

    vector<ll> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[n] = fpow(fc[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
    auto cb = [&](int a, int b) -> ll {
        if (a < 0 || b < 0 || a < b) return 0;
        ll ret = (fc[a] * ifc[b]) % MOD;
        ret = (ret * ifc[a - b]) % MOD;
        return ret;
    };
    if (n == 2) {
        cout << 2 << '\n';
        return;
    }

    ll A = cb(n - 1, 3);
    A = (A * fc[n - 3]) % MOD;
    A = (A * cb(n, k)) % MOD;
    A = (A * 2) % MOD;

    ll X = (cb(n - 2, k) + cb(n - 2, k - 2) + cb(n - 2, k - 1)) % MOD;
    ll B = (X * fc[n - 1]) % MOD;

    ll C = (n - 2) * fc[n - 1] % MOD;
    C = (C * cb(n, k)) % MOD;
    ll D = (fc[n - 1] * 2 * X) % MOD;

    ll ans = (A + B) % MOD;
    ans = (ans * (n - 2)) % MOD;

    ans = (ans + C + D) % MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}