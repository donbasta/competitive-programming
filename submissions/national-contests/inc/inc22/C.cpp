#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll fpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int q;
    cin >> q;
    ll cur = 0;
    const ll MOD = 1e9 + 7;
    while (q--) {
        char c;
        ll pw;
        cin >> c >> pw;
        ll pw2 = fpow(2, pw, MOD);
        if (c == '+') {
            cur = (cur + pw2) % MOD;
        } else if (c == '-') {
            cur = (cur - pw2) % MOD;
        }
        if (cur < 0) cur += MOD;
        if (cur == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}