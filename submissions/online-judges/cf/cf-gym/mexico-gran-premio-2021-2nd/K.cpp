#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e6;
ll dp[N + 5], rem[N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        b >>= 1;
        a =  (a * a) % MOD;
    }
    return ret;
}

void init() {
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[i - 1] * 2) % MOD;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            rem[j] = (rem[j] + dp[i]) % MOD;
        }
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[i] - rem[i] + MOD) % MOD;
    }
}

void solve() {
    int k;
    cin >> k;

    ll ans = 0;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            ans = (ans + dp[i]) % MOD;
            if (i * i != k) {
                ans = (ans + dp[k / i]) % MOD;
            }
        }
    }
    if (k > 1) {
        ans = (ans + 2) % MOD;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}