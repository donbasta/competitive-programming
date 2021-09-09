#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
string s;

const ll INF = 1e18;

void solve() {
    cin >> n >> k >> s;
    vector<int> is(n);
    for (int i = 0; i < n; i++) {
        is[i] = (int) (s[i] - '0');
    }
    vector<vector<ll>> f(k + 1, vector<ll>(k + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> f[i][j];
        }
    }
    ll awal = 0;
    for (int i = 0; i < n - 1; i++) {
        awal += f[is[i]][is[i + 1]];
    }
    vector<ll> dp(k + 1, INF);
    dp[is[0]] = 0;
    dp[is[1]] = f[is[0]][is[1]];
    for (int i = 2; i < n; i++) {
        ll temp = INF;
        for (int j = 1; j <= k; j++) {
            if (dp[j] == INF) continue;
            temp = min(temp, dp[j] + f[j][is[i]]);
        }
        dp[is[i]] = min(dp[is[i]], temp);
    }
    ll akhir = dp[is[n - 1]];
    cout << awal - akhir << '\n';
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