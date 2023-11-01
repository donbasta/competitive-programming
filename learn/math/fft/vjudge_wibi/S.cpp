#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    ll n, k;
    cin >> n >> k;
    ll cur = 1;
    for (int i = 1; i <= k; i++) {
        cur = (cur * (n + i) % MOD * (n - i + 1) % MOD);
        cur = (cur * fpow(2 * i - 1, MOD - 2) % MOD * fpow(2 * i, MOD - 2) % MOD);
        cout << cur << ' ';
    }
    cout << '\n';
    return;
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