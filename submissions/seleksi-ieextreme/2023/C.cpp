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

void solve() {
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> ve;
    for (int i = 0; i < n; i++) {
        ll k, j;
        cin >> k >> j;
        ll nw = (k * x - j * (k + 1));
        if (nw < 0) {
            ve.push_back(x);
        } else {
            ve.push_back(nw);
        }
        // ve.push_back(max(nw, x));
    }
    sort(ve.begin(), ve.end());

    vector<ll> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ifc[n] = fpow(fc[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = (ifc[i + 1] * (i + 1)) % MOD;
    }

    auto combi = [&](ll a, ll b) -> ll {
        if (a < 0 || b < 0 || a < b) return 0;
        ll ret = (fc[a] * ifc[b]) % MOD;
        ret = (ret * ifc[a - b]) % MOD;
        return ret;
    };

    ll tot = 0;
    for (int i = m - 1; i < n; i++) {
        ve[i] %= MOD;
        ll cur = (ve[i] * combi(i, m - 1)) % MOD;
        tot = (tot + cur) % MOD;
    }
    ll all = combi(n, m);
    tot = (tot * fpow(all, MOD - 2)) % MOD;
    if (tot < 0) tot += MOD;
    cout << tot << '\n';
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