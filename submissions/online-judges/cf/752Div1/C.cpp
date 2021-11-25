#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MOD = 998244353;
const int MX = 1e5;

vector<pii> ve[MX + 5];

void precomp() {
    for (int i = 1; i <= MX; i++) {
        int sq = sqrt(i);
        for (int j = 1; j <= min(i - 1, sq); j++) {
            int potong = (i % j == 0) ? (i / j) : ((i + j - 1) / j);
            ve[i].emplace_back(j, potong);
        }
        for (int j = sq + 5; j >= 2; j--) {
            int r = (i / j) + ((i % j) != 0);
            if (r <= sq) {
                continue;
            }
            if (!ve[i].empty() && (r == ve[i].back().first)) {
                continue;
            }
            ve[i].emplace_back(r, j);
        }
        ve[i].emplace_back(i, 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int sz = ve[ar[i]].size();
        dp[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            int potong = ve[ar[i]][j].second;
            int r = ve[ar[i]][j].first;
            int l = (ar[i] % potong == 0) ? r : r - 1;
            if (i == 1) {
                dp[i][j] = ((potong - 1) % MOD);
                continue;
            }
            int bat = lower_bound(ve[ar[i - 1]].begin(), ve[ar[i - 1]].end(), make_pair(l + 1, -1)) - ve[ar[i - 1]].begin();
            dp[i][j] = (1LL * (potong - 1) * i + dp[i - 1][bat - 1]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][ve[ar[i]].size() - 1]) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    precomp();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}