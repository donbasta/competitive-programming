#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 2e5;

int lpf[M + 5], dp[M + 5], T[M + 5];

void el_psy_congroo() {
    int t, MOD;
    cin >> t >> MOD;

    for (int i = 2; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            if (lpf[j] == 0) lpf[j] = i;
        }
    }

    dp[1] = 1;
    int prev = 1;
    for (int i = 2; i <= M; i++) {
        vector<int> pf;
        int ni = i;
        while (ni > 1) {
            int p = lpf[ni];
            pf.push_back(p);
            while (ni % p == 0) {
                ni /= p;
            }
        }
        int b = pf.size();
        int lmao = 0;
        for (int msk = 1; msk < (1 << b); msk++) {
            int x = __builtin_popcount(msk);
            int tmp = 1;
            for (int t = 0; t < b; t++) {
                if ((msk >> t) & 1) tmp *= pf[t];
            }
            if (x & 1) {
                lmao = (lmao + T[tmp]) % MOD;
            } else {
                lmao = (lmao - T[tmp]) % MOD;
            }
        }
        dp[i] = (prev - lmao) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
        prev = (prev + dp[i]) % MOD;
        for (int msk = 1; msk < (1 << b); msk++) {
            int tmp = 1;
            for (int t = 0; t < b; t++) {
                if ((msk >> t) & 1) tmp *= pf[t];
            }
            T[tmp] = (T[tmp] + dp[i]) % MOD;
        }
    }

    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
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