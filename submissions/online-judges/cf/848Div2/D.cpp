#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;
const int N = 1e6;

ll iv[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return fpow(x, MOD - 2);
}

void precomp_inverse() {
    for (int i = 1; i <= N; i++) {
        iv[i] = inv(i);
    }
}

void solve() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int beda = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) beda++;
    }
    vector<ll> hehi(n);
    hehi[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        ll X = (n * iv[i + 1]) % MOD;
        ll Y = ((n - 1 - i) * iv[i + 1]) % MOD;
        Y = (Y * hehi[i + 1]) % MOD;
        hehi[i] = (X + Y) % MOD;
    }
    ll ans = 0;

    for (int i = 0; i < beda; i++) {
        ans = (ans + hehi[i]) % MOD;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precomp_inverse();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}