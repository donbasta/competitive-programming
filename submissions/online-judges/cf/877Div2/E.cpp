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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    if (k == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<ll> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * (m - i + 1) % MOD;
        f[i] = f[i] * fpow(i, MOD - 2) % MOD;
    }
    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        ll tmp = f[i] * fpow(k - 1, m - i) % MOD;
        ans = (ans + tmp) % MOD;
    }
    ans = (ans + fpow(k - 1, m)) % MOD;
    ans = (ans - fpow(k, m)) % MOD;
    if (ans < 0) ans += MOD;
    ans = (MOD - ans) % MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}