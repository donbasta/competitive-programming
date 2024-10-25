#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 2e5;

int n;
int L[N + 5], R[N + 5];
ll Inv[N + 5], ar[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ret;
}

inline ll inv(ll a) { return fpow(a, MOD - 2); }

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> R[i];
    }
    for (int i = 1; i <= n; i++) {
        Inv[i] = inv(R[i] - L[i] + 1);
    }
    ll ans = 0, bans;
    for (int i = 1; i <= n - 1; i++) {
        ll tmp = max(0, min(R[i], R[i + 1]) - max(L[i], L[i + 1]) + 1);
        tmp = (tmp * Inv[i]) % MOD;
        tmp = (tmp * Inv[i + 1]) % MOD;
        tmp = (1LL - tmp) % MOD;
        if (tmp < 0) tmp += MOD;
        ar[i] = tmp;
        ans = (ans + tmp) % MOD;
    }
    bans = ans;
    ans = (ans * ans) % MOD;
    for (int i = 1; i <= n - 1; i++) {
        ans = ans - ((ar[i] * ar[i]) % MOD);
        ans = ans + ar[i];
        ans %= MOD;
    }
    for (int i = 1; i <= n - 2; i++) {
        ans = ans - ((2LL * ar[i] * ar[i + 1]) % MOD);
        ll tmp = max(0, min({R[i], R[i + 1], R[i + 2]}) - max({L[i], L[i + 1], L[i + 2]}) + 1);
        tmp = (tmp * Inv[i]) % MOD;
        tmp = (tmp * Inv[i + 1]) % MOD;
        tmp = (tmp * Inv[i + 2]) % MOD;
        ans = ans + (2LL * (tmp + ar[i] + ar[i + 1] - 1) % MOD);
        ans %= MOD;
    }
    ans = (ans + 2LL * bans + 1) % MOD;
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
