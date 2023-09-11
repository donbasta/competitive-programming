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
    int n, k, mod;
    cin >> n >> k >> mod;
    ll tot = 0;

    vector<ll> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) fc[i] = (fc[i - 1] * i) % mod;
    ifc[n] = fpow(fc[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--) ifc[i] = (ifc[i + 1] * (i + 1)) % mod;

    auto combi = [&](int a, int b) -> ll {
        if (a < 0 || b < 0 || a < b) return 0;
        ll ret = fc[a] * ifc[b] % mod;
        ret = ret * ifc[a - b] % mod;
        return ret;
    };

    for (int dig = 0; dig < k; dig++) {
        vector<vector<ll>> dp(n, vector<ll>(k));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                ll tmp = 0;
                for (int kk = 0; kk < k; kk++) {
                    int cek = (kk + dig - j) % k;
                    if (cek < 0) cek += k;
                    if (cek == 0) continue;
                    tmp = (tmp + dp[i - 1][kk]) % mod;
                }
                dp[i][j] = tmp;
            }
        }
        ll ans = 0;
        for (int cnt = 1; cnt <= n; cnt++) {
            ll lmao = combi(n, cnt);
            int sisa = (2 * dig - dig * cnt) % k;
            if (sisa < 0) sisa += k;
            lmao = (lmao * dp[n - cnt][sisa]) % mod;
            ans = (ans + lmao) % mod;
        }
        tot = (tot + ans) % mod;
    }

    if (k % 2 == 0) {
        for (int i = 0; i < k / 2; i++) {
            // remove double between i and i + k / 2
            vector<vector<ll>> dp2(n, vector<ll>(k));
            dp2[0][0] = 1;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    ll tmp = 0;
                    for (int kk = 0; kk < k; kk++) {
                        int cek1 = (kk + i - j) % k;
                        int cek2 = (kk + i + (k / 2) - j) % k;
                        if (cek1 < 0) cek1 += k;
                        if (cek2 < 0) cek2 += k;
                        if (cek1 == 0) continue;
                        if (cek2 == 0) continue;
                        tmp = (tmp + dp2[i - 1][kk]) % mod;
                    }
                    dp2[i][j] = tmp;
                }
            }
            for (int ci = 1; ci < n; ci++) {
                for (int cj = 1; cj < n; cj++) {
                    if (ci + cj > n) continue;
                    int need = (2 * i - ci * i - cj * (i + k / 2)) % k;
                    if (need < 0) need += k;
                    ll lmao = combi(n, ci);
                    lmao = (lmao * combi(n - ci, cj)) % mod;
                    tot = (tot - lmao * dp2[n - ci - cj][need]) % mod;
                }
            }
        }
    }

    tot %= mod;
    if (tot < 0) tot += mod;

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