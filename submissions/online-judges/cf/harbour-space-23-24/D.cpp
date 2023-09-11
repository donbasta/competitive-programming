#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<string> ve(n);
    for (int i = 0; i < n; i++) cin >> ve[i];
    vector<vector<int>> dig(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dig[i][j] = ve[i][j] - '0';
        }
    }
    vector<vector<int>> need(n, vector<int>(n));
    vector<vector<int>> pre(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int atas = (i > 0) ? pre[i - 1][j] : 0;
            if (dig[i][j] != (atas & 1)) {
                need[i][j] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            int prv = (j > 0) ? need[i][j - 1] : 0;
            int nx = (j < n - 1) ? need[i][j + 1] : 0;
            pre[i][j] = prv + nx + need[i][j];
            int prv_atas = (i > 0 && j > 0) ? pre[i - 1][j - 1] : 0;
            int nx_atas = (i > 0 && j < n - 1) ? pre[i - 1][j + 1] : 0;
            int dbl_atas = (i > 1) ? pre[i - 2][j] : 0;
            int mid = (i > 0) ? need[i - 1][j] : 0;
            pre[i][j] += (prv_atas + nx_atas);
            if (i > 0 && j > 0 && j < n - 1) {
                pre[i][j] -= (dbl_atas + mid);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << i << ' ' << j << ' ' << need[i][j] << ' ' << pre[i][j] << '\n';
            ans += need[i][j];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}