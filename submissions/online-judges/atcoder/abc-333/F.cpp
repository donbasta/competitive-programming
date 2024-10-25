#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<ll>> p(n + 1, vector<ll>(n + 1));
    p[1][1] = 1;
    ll i2 = fpow(2, MOD - 2);
    vector<ll> ipw(n + 1), pw(n + 1);
    ipw[0] = pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        ipw[i] = (ipw[i - 1] * i2) % MOD;
        pw[i] = (pw[i - 1] * 2) % MOD;
    }
    for (int j = 2; j <= n; j++) {
        ll tmp = 0;
        for (int i = 1; i <= j - 1; i++) {
            tmp = (tmp + ipw[j + 1 - i] * p[i][j - 1]) % MOD;
        }
        tmp = tmp * pw[j] % MOD;
        tmp = tmp * fpow(pw[j] - 1, MOD - 2) % MOD;
        p[1][j] = tmp;
        for (int i = 2; i <= j; i++) {
            p[i][j] = (p[i - 1][j] + p[i - 1][j - 1]) % MOD;
            p[i][j] = (p[i][j] * ipw[1]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i][n] << ' ';
    }
    cout << '\n';
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