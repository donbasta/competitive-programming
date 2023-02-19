#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void solve() {
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i += 3) {
        vector<ll> tmp(3);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        sort(tmp.begin(), tmp.end());
        if (tmp[0] == tmp[2]) {
            ans = (ans * 3) % MOD;
        } else if (tmp[0] == tmp[1]) {
            ans = (ans * 2) % MOD;
        }
    }
    vector<ll> fc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n / 3; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ans = (ans * fc[n / 3]) % MOD;
    ans = (ans * inv(fc[n / 6])) % MOD;
    ans = (ans * inv(fc[n / 6])) % MOD;
    cout << ans << '\n';
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