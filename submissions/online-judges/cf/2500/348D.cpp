#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    const auto calc = [&](int x1, int y1, int x2, int y2) -> ll {
        vector<vector<ll>> dp(n, vector<ll>(m));
        if (s[x1][y1] != '#') {
            dp[x1][y1] = 1;
        }
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (i == x1 && j == y1) continue;
                if (s[i][j] == '#') continue;
                ll atas = (i > 0 ? dp[i - 1][j] : 0);
                ll kiri = (j > 0 ? dp[i][j - 1] : 0);
                dp[i][j] = (atas + kiri) % MOD;
            }
        }
        return dp[x2][y2];
    };

    ll A = calc(0, 1, n - 2, m - 1);
    ll B = calc(0, 1, n - 1, m - 2);
    ll C = calc(1, 0, n - 2, m - 1);
    ll D = calc(1, 0, n - 1, m - 2);
    // cerr << A << ' ' << B << ' ' << C << ' ' << D << '\n';
    ll ret = (A * D - B * C) % MOD;
    if (ret < 0) ret += MOD;
    cout << ret << '\n';
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