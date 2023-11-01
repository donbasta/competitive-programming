#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll f(ll lvl, ll dep, ll sz, ll ksg) {
    if (lvl <= 0 || dep <= 0) return 0;
    if (lvl == 1) {
        return 1 - ksg;
    }
    if (dep == 1) {
        return (((1ll << lvl) - 2 - ksg) <= sz);
    }
    if (ksg == 0) {
        ll a = 0;
        ll cur = 1;
        while (cur <= sz + 2) {
            cur *= 2, a++;
        }
        a--;
        ll p = max(1ll, lvl + 1 - a);
        if (p > dep) return 0;
        ll tmp = (1ll << dep) - (1ll << (p - 1));
        return tmp;
    }
    ll mid = (((1ll << lvl) - 2 - ksg) <= sz);
    ll ki, ka;
    if (ksg >= (1ll << (lvl - 2))) {
        ki = f(lvl - 1, dep - 1, sz, ksg - (1ll << (lvl - 2)));
        ka = f(lvl - 2, min(dep - 1, lvl - 2), sz, 0);
    } else {
        ki = f(lvl - 1, dep - 1, sz, 0);
        ka = f(lvl - 1, dep - 1, sz, ksg);
    }
    return ki + ka + mid;
}

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    if (n == 1 || k == 1) {
        cout << 1 << '\n';
        return;
    }

    ll mx_lvl = 1;
    while ((1ll << mx_lvl) - 1 < n) {
        mx_lvl++;
    }
    ll kosong = ((1ll << mx_lvl) - 1) - n;

    cout << f(mx_lvl, min(k, mx_lvl), n - k, kosong) << '\n';
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
