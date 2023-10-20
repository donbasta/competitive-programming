#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<string> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int ans = 0;
    for (int i = 0; i < (n / 2); i++) {
        for (int j = 0; j < (n / 2); j++) {
            char a = ve[i][j];
            char b = ve[j][n - 1 - i];
            char c = ve[n - 1 - i][n - 1 - j];
            char d = ve[n - 1 - j][i];
            int mx = max({a, b, c, d});
            ans += 4 * mx - (a + b + c + d);
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