#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
const int N = 500;
const int K = 10;

int dp[N + 5][N + 5][K + 5];
int dp2[N + 5][N + 5][K + 5];
int n, m, k;
int hori[N + 5][N + 5];
int ver[N + 5][N + 5];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
            cin >> hori[i][j];
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ver[i][j];
        }
    }
    if (k & 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return;
    }
    k /= 2;
    for (int kk = 1; kk <= k; kk++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int mn = INF;
                for (int l = 1; l < kk; l++) {
                    mn = min(mn, dp[i][j][l] + dp[i][j][kk - l]);
                }
                int mn2 = INF, tmp;
                if (j > 1) {
                    tmp = (hori[i][j - 1] + dp2[i][j - 1][kk - 1]);
                    mn = min(mn, 2 * tmp);
                    mn2 = min(mn2, tmp);
                }
                if (j < m) {
                    tmp = (hori[i][j] + dp2[i][j + 1][kk - 1]);
                    mn = min(mn, 2 * tmp);
                    mn2 = min(mn2, tmp);
                }
                if (i > 1) {
                    tmp = (ver[i - 1][j] + dp2[i - 1][j][kk - 1]);
                    mn = min(mn, 2 * tmp);
                    mn2 = min(mn2, tmp);
                }
                if (i < n) {
                    tmp = (ver[i][j] + dp2[i + 1][j][kk - 1]);
                    mn = min(mn, 2 * tmp);
                    mn2 = min(mn2, tmp);
                }
                dp[i][j][kk] = mn;
                dp2[i][j][kk] = mn2;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j][k] << ' ';
        }
        cout << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}