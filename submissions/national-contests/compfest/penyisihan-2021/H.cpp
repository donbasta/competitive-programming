#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 2e5;

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

ll comb(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    ll ret = (fc[a] * ifc[a - b]) % MOD;
    ret = (ret * ifc[b]) % MOD;
    return ret;
}

void solve() {
    int tc;
    cin >> tc;
    ll ret = 0;
    while (tc--) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll ans = comb(n + m, k);
        if (ans < 0) ans += MOD;
        ret = (ret + ans) % MOD;
    }
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }

    int TC = 1;
    // cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}