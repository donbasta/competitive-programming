#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 800;
const int M = 4000;
const ld INF = 1e18;
const ld TS = 1.1;

int n, m;
int a[M + 5], b[M + 5];
ld c[M + 5];
ld dp[N + 5][N + 5];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = log(c[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -INF;
        }
        for (int j = 0; j < m; j++) {
            dp[i][b[j]] = max(dp[i][b[j]], dp[i - 1][a[j]] + c[j]);
        }
    }
    bool ada = 0;
    for (int i = 0; i < m; i++) {
        if (dp[n - 1][a[i]] >= 0.0) {
            ld cek = dp[n - 1][a[i]] + c[i];
            if (cek > dp[n - 1][b[i]] && cek >= log(TS)) {
                ada = 1; 
                break;
            }
        }
    }
    cout << (ada ? "inadmissible" : "admissible") << '\n';
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