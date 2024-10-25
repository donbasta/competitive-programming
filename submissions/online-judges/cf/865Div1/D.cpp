#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
ll inv2;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll f(ll x) {  // x + (x - 2) + ...
    if (x <= 0) return 0;
    ll cnt = (x + 2) / 2;
    ll bwh = (x & 1);
    ll ret = (bwh + x) % MOD;
    cnt %= MOD;
    ret = (ret * cnt) % MOD;
    ret = (ret * inv2) % MOD;
    return ret;
}

void el_psy_congroo() {
    ll n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }
    ll ret;
    if (m == 1) {
        ret = n;
    } else if (m == 2) {
        ll r = 1;
        while (r <= n) r *= 2;
        ll bat = r - 2 - n;
        ret = (f(bat) + n) % MOD;
    } else {
        ret = f(n);
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    inv2 = fpow(2, MOD - 2);
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}