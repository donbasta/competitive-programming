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
    int n, d;
    cin >> n >> d;
    vector<int> ar(n);
    int piv = -1;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == d) piv = i;
    }
    assert(piv != -1);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (i < piv && ar[i] < d) {
            x++;
        } else if (i > piv && ar[i] > d) {
            y++;
        }
    }

    vector<int> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (1ll * fc[i - 1] * i) % MOD;
    }
    ifc[n] = fpow(fc[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;
    }

    auto comb = [&](int a, int b) {
        if (a < 0 || b < 0 || a < b) return 0;
        int ret = (1ll * fc[a] * ifc[b]) % MOD;
        ret = (1ll * ret * ifc[a - b]) % MOD;
        return ret;
    };

    int ans = 0;
    for (int i = 0; i <= min(x, y); i++) {
        int A = comb(x, i);
        A = (1ll * A * fpow(-3, i)) % MOD;
        A = (1ll * A * fpow(2, x - i)) % MOD;
        int B = comb(x + y - i, x);
        B = (1ll * B * fpow(2, y - i)) % MOD;
        int C = (1ll * A * B) % MOD;
        ans = (ans + C) % MOD;
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