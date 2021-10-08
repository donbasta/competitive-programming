#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int N = 1e4;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1LL * ret * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

struct Combi {
    vector<int> fc, ifc;
    void init(int n) {
        fc.resize(n + 5), ifc.resize(n + 5);
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = (1LL * fc[i - 1] * i) % MOD;
        }
        ifc[n] = fpow(fc[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            ifc[i] = (1LL * ifc[i + 1] * (i + 1)) % MOD;
        }
    }
    int cb(int a, int b) {
        if (a < 0 || b < 0 || a < b) {
            return 0;
        }
        int ret = (1LL * fc[a] * ifc[b]) % MOD;
        ret = (1LL * ret * ifc[a - b]) % MOD;
        return ret;
    }
} combi;

int p, s, r;

void solve() {
    cin >> p >> s >> r;

    const auto calc = [&](int a, int b, int c) -> int {
        if (a == 0 && b == 0) {
            return 1;
        }
        int ret = 0;
        for (int i = 0; i <= b; i++) {
            int tmp = (1LL * combi.cb(b, i) * combi.cb(a + b - 1 - i * (c + 1), b - 1)) % MOD;
            if (i & 1) ret = (ret - tmp) % MOD;
            else ret = (ret + tmp) % MOD;
        }
        return ret;
    };

    int ans = 0;
    for (int i = r; i <= s; i++) {
        if (i == 0) {
            if (s == 0) {
                ans = (ans + fpow(p, MOD - 2)) % MOD;
            }
            continue;
        }
        int tmp = 0;
        int atas = (i == 0 ? p : min(p, s / i));
        for (int j = 1; j <= atas; j++) {
            int now = (1LL * fpow(j, MOD - 2) * combi.cb(p - 1, j - 1)) % MOD;
            now = (1LL * now * calc(s - i * j, p - j, i - 1)) % MOD;
            tmp = (tmp + now) % MOD;
        }
        ans = (ans + tmp) % MOD;
    }
    ans = (1LL * ans * fpow(combi.cb(s + p - r - 1, p - 1), MOD - 2) % MOD);
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    combi.init(N);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}