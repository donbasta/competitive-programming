#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;
const int MX = 3e5;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int fac[MX + 5], ifac[MX + 5];
void init_fac() {
    fac[0] = 1;
    for (int i = 1; i <= MX; i++) {
        fac[i] = (1ll * fac[i - 1] * i) % MOD;
    }
    ifac[MX] = fpow(fac[MX], MOD - 2);
    for (int i = MX - 1; i >= 0; i--) {
        ifac[i] = (1ll * ifac[i + 1] * (i + 1)) % MOD;
    }
}

int combi(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    int ret = (1ll * fac[a] * ifac[a - b]) % MOD;
    ret = (1ll * ret * ifac[b]) % MOD;
    return ret;
}

void solve() {
    init_fac();
    int n, k;
    cin >> n >> k;
    ll ret = 0;
    for (int kosong = 0; kosong <= n; kosong++) {
        int tmp = combi(n, kosong);
        tmp = (1ll * tmp * fac[n - kosong]) % MOD;
        if (k >= n - kosong) {
            tmp = (1ll * tmp * fac[n - kosong]) % MOD;
            int d = k - n + kosong + 1;
            int A = fpow(n - kosong + 1, d);
            int B = fpow(n - kosong, d);
            tmp = (1ll * tmp * (A - B)) % MOD;
            if (tmp < 0) tmp += MOD;
            ret = (ret + tmp) % MOD;
        }
    }
    ret %= MOD;
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
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