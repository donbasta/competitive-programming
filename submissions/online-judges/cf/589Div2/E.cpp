#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll n, k;
    cin >> n >> k;

    const ll MOD = 1e9 + 7;
    auto fpow = [&](ll a, ll b) -> ll {
        ll ret = 1;
        while (b) {
            if (b & 1) ret = (ret * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ret;
    };

    vector<ll> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = fc[i - 1] * i % MOD;
    }
    ifc[n] = fpow(fc[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1) % MOD;
    }

    auto comb = [&](ll a, ll b) -> ll {
        if (a < 0 || b < 0 || a < b) return 0;
        ll ret = fc[a] * ifc[b] % MOD;
        ret = ret * ifc[a - b] % MOD;
        return ret;
    };

    vector<ll> a(n + 1), b(n + 1);
    a[0] = b[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] * k % MOD;
        b[i] = b[i - 1] * (k - 1) % MOD;
    }
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        ll term = comb(n, i) * fpow(k - 1, n * (n - i)) % MOD;
        ll lmao = fpow(a[i] - b[i], n) % MOD;
        term = term * lmao % MOD;
        if ((n - i) & 1) {
            ans = (ans - term) % MOD;
        } else {
            ans = (ans + term) % MOD;
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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