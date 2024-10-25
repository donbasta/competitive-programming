#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

void el_psy_congroo() {
    int nn;
    cin >> nn;
    vector<string> s(nn);
    string ss;
    for (int i = 0; i < nn; i++) {
        cin >> s[i];
        ss += s[i];
    }
    int n = ss.length();
    vector<int> fibo = {1, 1, 2};
    while (fibo.back() < n) {
        fibo.push_back(fibo.back() + fibo[fibo.size() - 2]);
    }
    const int T = fibo.size();

    const int B[2] = {3, 5}, M[2] = {1000000007, 1000000009};
    vector<vector<int>> pw(2, vector<int>(n));
    pw[0][0] = pw[1][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pw[j][i] = (1ll * pw[j][i - 1] * B[j]) % M[j];
        }
    }
    vector<vector<int>> fibos = {{1, 1, 1}, {2, 2, 1}};  // h1, h2, len
    for (int i = 2; i < T; i++) {
        vector<int> cur(3);
        cur[2] = fibos.back()[2] + fibos[fibos.size() - 2][2];
        assert(cur[2] == fibo[i]);
        for (int j = 0; j < 2; j++) {
            cur[j] = (1ll * fibos.back()[j] * pw[j][fibos[fibos.size() - 2][2]] + fibos[fibos.size() - 2][j]) % M[j];
        }
        fibos.emplace_back(cur);
    }

    vector<int> dp(n);
    vector<vector<int>> hash(n);
    int pref = 1;

    vector<int> tmp(2);
    for (int i = 0; i < n; i++) {
        int cur = (ss[i] - '0' + 1);
        for (int j = 0; j < 2; j++) {
            tmp[j] = (1ll * B[j] * tmp[j] + cur) % M[j];
        }
        hash[i] = tmp;
    }

    auto get_rolling_hash = [&](int a, int b) -> vector<int> {
        vector<int> ret(2);
        for (int j = 0; j < 2; j++) {
            ret[j] = hash[b][j];
            if (a > 0) {
                ret[j] = (ret[j] - 1ll * hash[a - 1][j] * pw[j][b - a + 1]) % M[j];
                if (ret[j] < 0) ret[j] += M[j];
            }
        }
        return ret;
    };

    for (int i = 1; i < n; i++) {
        dp[i] = pref;
        dp[i] = (dp[i] - dp[i - 1]) % MOD;
        for (int j = 2; j < T; j++) {
            int e = fibo[j];
            if (e > i + 1) break;
            if (e == i + 1) {
                vector<int> h = get_rolling_hash(0, i);
                if (h[0] == fibos[j][0] && h[1] == fibos[j][1]) {
                    dp[i] = (dp[i] - 1) % MOD;
                }
            } else {
                vector<int> h = get_rolling_hash(i - e + 1, i);
                if (h[0] == fibos[j][0] && h[1] == fibos[j][1]) {
                    dp[i] = (dp[i] - dp[i - e]) % MOD;
                }
            }
        }
        pref = (pref + dp[i]) % MOD;
    }

    int cur_len = 0;
    for (int i = 0; i < nn; i++) {
        cur_len += s[i].length();
        int ret = dp[cur_len - 1] % MOD;
        if (ret < 0) ret += MOD;
        cout << ret << '\n';
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