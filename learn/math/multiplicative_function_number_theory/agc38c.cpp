#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;
const int M = 1e6;

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
    int n;
    cin >> n;
    vector<int> ar(n), cnt(M + 1), f(M + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            f[i] = (f[i] + 1ll * cnt[j] * j) % MOD;
        }
    }

    // linear sieve
    vector<int> primes, conv(M + 1);
    conv[1] = 1;
    vector<bool> comp(M + 1);
    for (int i = 2; i <= M; i++) {
        if (!comp[i]) {
            primes.push_back(i);
            conv[i] = ((1ll - i) * fpow(i, MOD - 2)) % MOD;
            if (conv[i] < 0) conv[i] += MOD;
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= M; j++) {
            comp[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                conv[i * primes[j]] = (1ll * conv[i] * fpow(primes[j], MOD - 2)) % MOD;
                break;
            } else {
                conv[i * primes[j]] = (1ll * conv[i] * conv[primes[j]]) % MOD;
            }
        }
    }

    // sum_t conv(t) * f[t]
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        int ff = (1ll * f[i] * f[i]) % MOD;
        ans = (ans + 1ll * conv[i] * ff) % MOD;
    }
    for (int i = 0; i < n; i++) {
        ans = (ans - ar[i]) % MOD;
    }
    ans = (1ll * ans * fpow(2, MOD - 2)) % MOD;
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
