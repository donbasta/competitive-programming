#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const int B = 30;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll ans = 0;
    for (int i = 0; i < B; i++) {
        ll lol = 0;
        vector<ll> ve(n), tmp(n);
        for (int j = 0; j < n; j++) {
            ve[j] = ((ar[j] >> i) & 1);
        }
        tmp[0] = ve[0];
        for (int j = 1; j < n; j++) {
            tmp[j] = (tmp[j - 1] ^ ve[j]);
        }
        vector<vector<ll>> pref(2, vector<ll>(n + 1));
        pref[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            pref[0][j] = pref[0][j - 1] + (tmp[j - 1] == 0);
            pref[1][j] = pref[1][j - 1] + (tmp[j - 1] == 1);
        }
        vector<vector<ll>> lmao(2, vector<ll>(n + 1));
        lmao[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            lmao[0][j] = lmao[0][j - 1] + pref[0][j];
            lmao[1][j] = lmao[1][j - 1] + pref[1][j];
        }
        for (int j = 1; j <= n; j++) {
            int cur = tmp[j - 1];
            lol = (lol + lmao[1 - cur][j - 1]) % MOD;
        }
        lol = (lol * (1ll << i)) % MOD;
        ans = (ans + lol) % MOD;
    }
    if (ans < 0) ans += MOD;
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