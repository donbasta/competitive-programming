#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e5;

ll n, k;
ll fc[N + 5], ifc[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    } 
    return ret;
} 

inline ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void init() {
    fc[0] = ifc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
        ifc[i] = (ifc[i - 1] * inv(i)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < 0 || b < 0 || a < b) return 0;
    ll ret = fc[a];
    ret = (ret * ifc[b]) % MOD;
    ret = (ret * ifc[a - b]) % MOD;
    return ret;
}

void solve() {
    cin >> n >> k;
    ll ans = 0;
    for (ll j = 1; j <= n; j++) {
        ll X = (j * C(n - (k - 1) * (j - 1), j)) % MOD;
        X = (X - (j + 1) * )
        ll tmp = j;
        tmp = (tmp * (X + Y)) % MOD;
        tmp = tmp * fc[n - j] % MOD;
        tmp = tmp * ifc[n] % MOD;
        ans = (ans + tmp) % MOD;

    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}