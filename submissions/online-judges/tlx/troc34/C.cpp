#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 1e9 + 7;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

void el_psy_congroo() {
    int n, x;
    cin >> n >> x;
    if (x & (x - 1)) {
        cout << -1 << '\n';
        return;
    }
    int t = 0;
    while (x > 1) {
        x >>= 1, t++;
    }
    if (t > n - 1) {
        cout << -1 << '\n';
        return;
    }
    // C(n - 1, t);
    // (n - 1) * ... * (n - t + 1) / (t * ... * 1)
    int ans = 1;
    for (int i = n - 1; i >= n - t; i--) {
        ans = (1ll * ans * i) % MOD;
    }
    for (int i = 1; i <= t; i++) {
        ans = (1ll * ans * fpow(i, MOD - 2)) % MOD;
    }
    cout << ans << '\n';
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