#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
const int N = 4e5;
const ll MOD = 998244353;
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

void init_fac() {
    fc[0] = ifc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[N] = fpow(fc[N], MOD - 2);
    for (int i = N - 1; i >= 1; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }
}
 
void solve() {
    ll n;
    cin >> n;
    ll ans = (fc[2 * n] * fpow(2LL, n)) % MOD;
    ans = (ans * ifc[n]) % MOD;
    ans = (ans * fpow(n + 1, MOD - 2)) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    init_fac();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
