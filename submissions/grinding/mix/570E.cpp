#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const ll MOD = 1e9 + 7;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<string> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    if (ve[0][0] != ve[n - 1][m - 1]) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(max(m, n))));
    dp[0][0][0] = 1;
    int len = (m + n - 1);
    for (int i = 1; i < (len) / 2; i++) {
        int l1 = max(0, i + 1 - m);
        int r1 = min(n - 1, i);
        for (int j = l1; j <= r1; j++) {
            for (int k = 0; k <= r1 - l1; k++) {
                int p1 = j, q1 = len - j;
                int p2 = n - 1 - p1, q2 = m - 1 - q1;
                if (ve[p1][q1] != ve[p2][q2]) continue;
                for (auto d1 : {{-1, 0}, {0, -1}}) {
                    for (auto d2 : {{1, 0}, {0, 1}}) {
                        int pp1 = p1 + d1[0], qq1 = q1 + d1[1];
                        int pp2 = p2 + d2[0], qq2 = q2 + d2[1];
                        if (pp1 < 0 || pp1 >= n || qq1 < 0 || qq1 >= m) continue;
                        if (pp2 < 0 || pp2 >= n || qq2 < 0 || qq2 >= m) continue;
                        if (ve[pp1][qq1] != ve[pp2][qq2]) continue;
                        dp[p1][q1][k] = (dp[p1][q1][k] + dp[pp1][qq1][]) % MOD;
                    }
                }
                dp[j][len - j][k]
            }
        }
    }
    ll ans = 0;
    if (len & 1) {
    } else {
        int L = max(0, len / 2 - m);
        int R = min(n - 1, len / 2 - 1);
        for (int i = L; i <= R; i++) {
            if (len / 2 - i < m - 1) ans = (ans + dp[i][len / 2 - 1 - i][]) % MOD;
            if (i < n - 1) ans = (ans + dp[i][len / 2 - 1 - i][]) % MOD;
        }
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