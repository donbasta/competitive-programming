#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 500;

void solve() {
    int n;
    cin >> n;
    vector<int> ve;
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        if (len == 2) {
            cnt++;
        } else {
            ve.emplace_back(len);
            sum += len;
        }
    }
    int sz = (int)ve.size();
    if (sz == 0) {
        cout << "YES" << '\n';
        return;
    }
    vector<vector<bool>> dp(sz + 1, vector<bool>(MX * MX + 1));
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            dp[i][0] = dp[i][ve[i]] = true;
            continue;
        }
        for (int j = 0; j <= MX * MX; j++) {
            dp[i][j] = (dp[i][j] || dp[i - 1][j]);
            if (j >= ve[i]) {
                dp[i][j] = (dp[i][j] || dp[i - 1][j - ve[i]]);
            }
        }
    }
    for (int i = cnt; i >= 0; i--) {
        if ((sum % 2 == 0) && dp[sz - 1][sum / 2]) {
            cout << "YES" << '\n';
            return;
        }
        for (int j = MX * MX; j >= 0; j--) {
            if (j >= 2) {
                dp[sz - 1][j] = (dp[sz - 1][j] || dp[sz - 1][j - 2]);
            }
        }
        sum += 2;
    }
    cout << "NO" << '\n';
    return;
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