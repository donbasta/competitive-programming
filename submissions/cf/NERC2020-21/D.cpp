#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, d;
const ld INF = 1e9;

void solve() {
    cin >> n >> d;
    vector<int> a(n + 1);
    vector<vector<ld>> dp(n + 1, vector<ld>(10, -INF));
    vector<vector<pair<bool, int>>> gg(n + 1, vector<pair<bool, int>>(10, make_pair(false, -1)));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1][a[1] % 10] = log(a[1]);
    gg[1][a[1] % 10] = {true, -1};

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = dp[i - 1][j];
            gg[i][j] = {false, j};
        }
        if (dp[i][a[i] % 10] < log(a[i])) {
            dp[i][a[i] % 10] = log(a[i]);
            gg[i][a[i] % 10] = {true, -1};
        }
        for (int j = 0; j <= 9; j++) {
            int mul = (j * a[i]) % 10;
            ld tmp = dp[i - 1][mul];
            if (dp[i - 1][j] != -INF) {
                tmp = max(tmp, dp[i - 1][j] + log(a[i]));
            }
            if (tmp > dp[i][mul]) {
                dp[i][mul] = tmp;
                if (tmp == dp[i - 1][mul]) {
                    gg[i][mul] = {false, mul};
                } else if (tmp == dp[i - 1][j] + log(a[i])) {
                    gg[i][mul] = {true, j};
                }
            }
        }
    }
    if (dp[n][d] == -INF) {
        cout << -1 << '\n';
        return;
    }
    int cur = n, cur_dig = d;
    vector<int> ans;
    while (cur) {
        if (gg[cur][cur_dig].first) {
            ans.push_back(a[cur]);
            cur_dig = gg[cur][cur_dig].second;
            cur--;
        } else {
            cur--;
        }
        if (cur_dig == -1) break;
    } 
    sort(ans.begin(), ans.end());
    cout << (int) ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
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