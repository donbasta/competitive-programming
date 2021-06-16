#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int f(const vector<int>& ve) {
    int n = (int)ve.size();
    if (n <= 1) return 0;
    // for (auto e : ve) {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = 1;
    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        int dif1 = ve[i] - ve[i - 1];
        int dif2 = (i == 1 ? -1 : ve[i] - ve[i - 2]);
        dp[0][i] = 1 + min (dp[0][i - 1], dp[1][i - 1]);
        if (dif2 == 2) {
            dp[1][i] = dp[0][i - 2] + 1;
        } else if (dif1 <= 2) {
            dp[1][i] = dp[0][i - 1];         
        } else {
            dp[1][i] = min (dp[0][i - 1], dp[1][i - 1]);
        }
    }
    return min (dp[0][n - 1], dp[1][n - 1]);
}

void solve() {
    string s;
    cin >> s;
    int n = (int)s.length();
    vector<int> ve[26];
    for (int i = 0; i < n; i++) {
        int dig = (int) s[i] - 'a';
        // cerr << dig << '\n';
        ve[dig].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += f(ve[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}