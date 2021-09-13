#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

ll m, n;

void solve() {
    cin >> n >> m;
    m %= MOD;
    if (n == 1) {
        cout << m << '\n';
        return;
    }
    if (n == 2) {
        ll ret = (m * (m - 1)) % MOD;
        if (ret < 0) ret += MOD;
        cout << ret << '\n';
        return;
    }
    if (m == 1) {
        cout << 0 << '\n';
        return;
    }
    if (m == 2 && (n % 2 == 1)) {
        cout << 0 << '\n';
        return;
    } else if (m == 2 && (n % 2 == 0)) {
        cout << 2 << '\n';
        return;
    }

    ll ans = (fpow(m - 1, n)) % MOD;
    if (n % 2 == 1) {
        ans = (ans - (m - 1)) % MOD;
    } else {
        ans = (ans + (m - 1)) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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