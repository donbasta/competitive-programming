#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll skor = 0;
    int n, d;
    cin >> n >> d;
    vector<vector<int>> a(2, vector<int>(n + 1));
    vector<vector<int>> p(2, vector<int>(n + 1));
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] += j;
        }
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
        }
    }
    vector<pair<int, int>> from(n + 1);
    for (int i = 0; i <= n; i++) {
        int sel = a[0][i] - a[1][i];
        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= n; k++) {
                if (a[0][j] - a[1][k] == sel) {
                    from[i].emplace_back(j, k);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
        }
    }

    const ll INF = 1e18;
    vector<vector<ll>> memo(n + 1, vector<ll>(n + 1, INF));
    vector<vector<ll>> memo1(n + 1, vector<ll>(n + 1, INF));
    vector<vector<ll>> memo2(n + 1, vector<ll>(n + 1, INF));
    const function<ll(int, int)> lol1 = [&](int i, int j) -> ll {
        if (memo1[i][j] != INF) return memo1[i][j];
        return memo[i][j] = min(lol1(i + 1, j), dp(i, j));
    };
    const function<ll(int, int)> lol2 = [&](int i, int j) -> ll {
        if (memo2[i][j] != INF) return memo2[i][j];
        return memo2[i][j] = min(lol2(i, j + 1), dp(i, j));
    };
    const function<ll(int, int)> dp = [&](int i, int j) -> ll {
        if (i == n && j == n) return 0;
        if (memo[i][j] != INF) return memo[i][j];
        ll ret = INF;
        if (i == j) {
            for (auto x : from[i]) {
                ret = min(ret, dp(x.first, x.second));
            }
        } else if (i < j) {
            ret = -d + lol1(i + 1, j);
            memo1[i][j] = min(memo1[i + 1][j], ret);
            // return -d + min(dp(i + 1, j), dp(i + 2, j), ..., dp(n, j));
        } else if (i > j) {
            ret = -d + lol2(i, j + 1);
            memo2[i][j] = min(memo2[i][j + 1], ret);
            // return -d + min(dp(i, j + 1), dp(i, j + 2), ..., dp(i, n));
        }
        return memo[i][j] = ret;
    };

    cout << dp(0, 0) << '\n';
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