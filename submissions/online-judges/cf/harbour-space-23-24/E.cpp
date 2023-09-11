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

int get_k_first_digit(int x, int k) {
    if (k == 30) return x;
    int mask = (1 << k) - 1;
    mask <<= (30 - k);
    return (x & mask);
}

void solve() {
    int n;
    cin >> n;
    int s[n];
    unordered_map<int, int> cnt[31];
    int pref[n][31];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int k = 1; k <= 30; k++) {
            pref[i][k] = get_k_first_digit(s[i], k);
            cnt[k][pref[i][k]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int b = 29; b >= 0; b--) {
            int lmao = pref[i][30 - b];
            lmao = lmao ^ (1 << b);
            if (cnt[30 - b].find(lmao) != cnt[30 - b].end()) {
                ans = (1ll * ans + cnt[30 - b][lmao] * (2 * tmp + 3)) % MOD;
            }
            tmp += ((s[i] >> b) & 1);
        }
        ans = (1ll * ans + 2ll * cnt[30][s[i]] * (tmp + 1)) % MOD;
    }
    ans = (1ll * ans * fpow(2, MOD - 2)) % MOD;

    int den = fpow(n, MOD - 2);
    den = (1ll * den * den) % MOD;
    ans = (1ll * ans * den) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}