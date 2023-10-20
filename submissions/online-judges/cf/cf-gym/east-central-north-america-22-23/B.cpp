#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

bool dp[1001][1001];
int ar[1001];

void solve() {
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = c; j >= 0; j--) {
            for (int k = c; k >= 0; k--) {
                if (j >= ar[i])
                    dp[j][k] |= dp[j - ar[i]][k];
                if (k >= ar[i])
                    dp[j][k] |= dp[j][k - ar[i]];
            }
        }
    }
    for (int i = 2 * c; i >= 0; i--) {
        int mx = INF;
        int p = -1, q = -1;
        for (int j = max(0, i - c); j <= min(i, c); j++) {
            if (dp[j][i - j]) {
                if (abs(i - 2 * j) < mx) {
                    mx = abs(i - 2 * j);
                    p = j, q = i - j;
                }
            }
        }
        if (mx < INF) {
            cout << max(p, q) << ' ' << min(p, q) << '\n';
            return;
        }
    }
    cout << 0 << ' ' << 0 << '\n';
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