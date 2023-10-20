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
    int n, k;
    cin >> n >> k;
    vector<int> f(k + 1);
    for (int i = k; i >= 1; i--) {
        int tmp = fpow(k / i, n);
        for (int j = 2 * i; j <= k; j += i) {
            tmp = (tmp - f[j]) % MOD;
        }
        f[i] = tmp;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans = (1ll * i * f[i] + ans) % MOD;
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
        el_psy_congroo();
    }

    return 0;
}