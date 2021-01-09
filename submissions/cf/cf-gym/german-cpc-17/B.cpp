#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

ll n, m, c;
ll pos, cur;

void solve() {
    cin >> n >> m >> c;
    pos = fpow(c, n * n);
    for (ll i = 1; i <= m; i++) {
        ll tmp = fpow(pos, __gcd(m, i));
        cur = (cur + tmp) % MOD;
    }
    cur = (cur * inv(m)) % MOD;
    if (cur < 0) cur += MOD;
    cout << cur << '\n';
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