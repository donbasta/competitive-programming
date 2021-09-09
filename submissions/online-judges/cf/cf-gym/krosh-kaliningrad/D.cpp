#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 5000;

ll dp[N + 10];
ll fc[2 * N + 5], ifc[2 * N + 5];

int k;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) { ret = (ret * a) % MOD; }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

inline ll inv(ll a) { return fpow(a, MOD - 2); }

void init_fac() {
    fc[0] = 1;
    for(int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = inv(fc[N]);
    for(int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = fc[a];
    ret = (ret * ifc[b]) % MOD;
    ret = (ret * ifc[a - b]) % MOD;
    return ret;
}

void solve() {
    init_fac();

    cin >> k;
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            ll tmp = C(i, j) * dp[j] % MOD;
            dp[i] = (dp[i] + tmp) % MOD;
        }
    }
    cout << dp[k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}