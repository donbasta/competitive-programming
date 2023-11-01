#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = (1e9 + 7);
const ll MX = 4e18;

ll pc[61];

void precompute() {
    for (ll i = 2; i <= 60; i++) {
        ll pw = (1ll << i);
        ll tmp = 1, pw2 = 0;
        while (tmp < pw) {
            if (tmp > MX / i) {
                tmp = MX;
            } else {
                tmp *= i;
            }
            pw2++;
        }
        if (tmp >= pw * 2) {
            pc[i] = ((pw2 - 1) * (pw % MOD)) % MOD;
        } else {
            ll x = ((tmp - pw) % MOD) * (pw2 - 1) % MOD;
            ll y = ((pw * 2 - tmp) % MOD) * pw2 % MOD;
            pc[i] = (x + y) % MOD;
        }
    }
}

ll f(ll a) {
    if (a <= 3) return 0;
    ll ca = a;
    int pw = 0;
    while (ca > 1) {
        ca /= 2, pw++;
    }

    ll ret = 0;
    for (int i = 2; i <= pw - 1; i++) {
        ret = (ret + pc[i]) % MOD;
    }

    // find pw^something between 2^pw and a
    ll bat = (1ll << pw);
    ll tmp = 1, pw2 = 0;
    while (tmp < bat) {
        if (tmp > MX / pw) {
            tmp = MX;
        } else {
            tmp *= pw;
        }
        pw2++;
    }
    if (tmp <= a) {
        ll x = ((tmp - bat) % MOD) * (pw2 - 1) % MOD;
        ll y = ((a - tmp + 1) % MOD) * pw2 % MOD;
        ret = (ret + x) % MOD;
        ret = (ret + y) % MOD;
        return ret;
    }
    ret = (ret + ((a - bat + 1) % MOD) * (pw2 - 1)) % MOD;
    return ret;
}

void el_psy_congroo() {
    int q;
    cin >> q;

    precompute();
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ll ans = (f(r) - f(l - 1)) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}