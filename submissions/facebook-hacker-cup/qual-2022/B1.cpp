#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int INF = 2e9;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll q;
    cin >> q;
    vector<ll> x(q), y(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }
    ll A1 = 0, A2 = 0, B1 = 0, B2 = 0;
    ll X1 = 0, X2 = 0, Y1 = 0, Y2 = 0;
    for (int i = 0; i < n; i++) {
        A1 = (A1 + a[i]) % MOD;
        A2 = (A2 + a[i] * a[i]) % MOD;
        B1 = (B1 + b[i]) % MOD;
        B2 = (B2 + b[i] * b[i]) % MOD;
    }
    for (int i = 0; i < q; i++) {
        X1 = (X1 + x[i]) % MOD;
        X2 = (X2 + x[i] * x[i]) % MOD;
        Y1 = (Y1 + y[i]) % MOD;
        Y2 = (Y2 + y[i] * y[i]) % MOD;
    }
    ll ans = n * (X2 + Y2) % MOD;
    ans = (ans + q * (A2 + B2)) % MOD;
    ans = (ans - A1 * X1 * 2) % MOD;
    ans = (ans - B1 * Y1 * 2) % MOD;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
