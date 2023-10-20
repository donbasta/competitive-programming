#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 0 << '\n';
        return;
    }
    int r = n - k;
    vector<int> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (1ll * fc[i - 1] * i) % MOD;
    }
    ifc[n] = fpow(fc[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;
    }

    auto combi = [&](int a, int b) -> int {
        if (a < 0 || b < 0 || a < b) return 0;
        int ret = (1ll * fc[a] * ifc[b]) % MOD;
        ret = (1ll * ret * ifc[a - b]) % MOD;
        return ret;
    };

    if (k == 0) {
        cout << fc[n] << '\n';
        return;
    }
    int ans = 2;
    ans = (1ll * ans * combi(n, r)) % MOD;
    int tmp = 0;
    for (int i = r; i >= 1; i--) {
        int term = combi(r, i);
        term = (1ll * term * fpow(i, n)) % MOD;
        if ((r - i) & 1) {
            tmp = (1ll * tmp - term) % MOD;
        } else {
            tmp = (1ll * tmp + term) % MOD;
        }
    }
    ans = (1ll * ans * tmp) % MOD;
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