#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    int n, k;
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

    vector<ll> pw3(n + 1);
    pw3[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw3[i] = (pw3[i - 1] * 3) % MOD;
    }

    if (k == 0) {
        cout << pw3[n] << '\n';
        return;
    }

    auto comb = [&](ll a, ll b) -> ll {
        if (a < b || a < 0 || b < 0) return 0;
        return ((fc[a] * ifc[a - b]) % MOD) * ifc[b] % MOD;
    };

    ll ans = 0;
    for (int i = 1; i <= (n / 2); i++) {
        ll tmp = comb(n - k, i) * comb(k - 1, i - 1) % MOD;
        tmp = tmp * pw3[n - 2 * i] % MOD;
        ans = (ans + tmp) % MOD;
    }

    for (int i = 1; i <= (n + 1) / 2; i++) {
        ll tmp = comb(n - k, i - 1) * comb(k - 1, i - 1) % MOD;
        tmp = tmp * pw3[n + 1 - 2 * i] % MOD;
        ans = (ans + tmp) % MOD;
    }

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