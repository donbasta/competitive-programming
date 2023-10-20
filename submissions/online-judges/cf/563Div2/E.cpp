#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt;
    int r;
    for (int i = 0;; i++) {
        int pw = (1 << i);
        if (pw > n) {
            r = i - 1;
            break;
        }
        cnt.push_back(((n / pw) + 1) / 2);
    }

    const int mod = 1e9 + 7;
    auto fpow = [&](int a, int b) -> int {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1ll * ret * a) % mod;
            a = (1ll * a * a) % mod;
            b >>= 1;
        }
        return ret;
    };
    vector<int> fc(n + 1), ifc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (1ll * fc[i - 1] * i) % mod;
    }
    ifc[n] = fpow(fc[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % mod;
    }
    auto combi = [&](int a, int b) -> int {
        if (a < 0 || b < 0 || a < b) return 0;
        int ret = (1ll * fc[a] * ifc[b]) % mod;
        ret = (1ll * ret * ifc[a - b]) % mod;
        return ret;
    };
    int tmp = fc[cnt[0]];
    int ans = 0;
    int pref = cnt[0];
    for (int i = 1; i <= r; i++) {
        int cur = fc[cnt[i]];
        cur = (1ll * cur * combi(pref + cnt[i] - 1, pref)) % mod;
        tmp = (1ll * tmp * cur) % mod;
        pref += cnt[i];
    }
    ans = (1ll * ans + tmp) % mod;
    if ((1 << (r - 1)) * 3 <= n) {
        vector<int> cnt3(r), cnt2(r);
        for (int i = 0; i <= r - 1; i++) {
            cnt3[i] = ((n / ((1 << i) * 3)) + 1) / 2;
            cnt2[i] = cnt[i] - cnt3[i];
        }
        for (int i = 0; i <= r - 1; i++) {
            if (i == 0) {
                int sisa = 1;
                for (int j = 0; j <= r - 1; j++) {
                    sisa += cnt2[j];
                }
                tmp = fc[sisa];
                pref = sisa;
                for (int j = 0; j <= r - 1; j++) {
                    int cur = fc[cnt3[j]];
                    cur = (1ll * cur * combi(pref + cnt3[j] - 1, pref)) % mod;
                    tmp = (1ll * tmp * cur) % mod;
                    pref += cnt3[j];
                }
                ans = (1ll * ans + tmp) % mod;
            } else {
                tmp = fc[cnt[0]];
                pref = cnt[0];
                for (int j = 1; j < i; j++) {
                    int cur = fc[cnt[j]];
                    cur = (1ll * cur * combi(pref + cnt[j] - 1, pref)) % mod;
                    tmp = (1ll * tmp * cur) % mod;
                    pref += cnt[j];
                }
                int sisa = 1;
                for (int j = i; j <= r - 1; j++) {
                    sisa += cnt2[j];
                }
                tmp = (1ll * tmp * fc[sisa]) % mod;
                tmp = (1ll * tmp * combi(pref + sisa - 1, pref)) % mod;
                pref += sisa;
                for (int j = i; j <= r - 1; j++) {
                    int cur = fc[cnt3[j]];
                    cur = (1ll * cur * combi(pref + cnt3[j] - 1, pref)) % mod;
                    tmp = (1ll * tmp * cur) % mod;
                    pref += cnt3[j];
                }
                ans = (1ll * ans + tmp) % mod;
            }
        }
    }

    ans %= mod;
    if (ans < 0) ans += mod;
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