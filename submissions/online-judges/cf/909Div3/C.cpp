#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
    dp[0][(ar[0] & 1)] = ar[0];
    for (int i = 1; i < n; i++) {
        int cur = (ar[i] & 1);
        int prv = max(0, dp[i - 1][cur ^ 1]);
        dp[i][cur] = ar[i] + prv;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i][(ar[i] & 1)]);
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
        el_psy_congroo();
    }

    return 0;
}