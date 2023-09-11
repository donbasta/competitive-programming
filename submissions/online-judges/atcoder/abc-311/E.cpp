#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<ll>> dp(h + 1, vector<ll>(w + 1));
    vector<vector<bool>> is_hole(h + 1, vector<bool>(w + 1));
    vector<vector<int>> pref(h + 1, vector<int>(w + 1));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        is_hole[a][b] = true;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + is_hole[i][j];
        }
    }
    const function<int(int, int, int, int)> count = [&](int a, int b, int c, int d) -> int {
        return pref[c][d] - pref[c][b - 1] - pref[a - 1][d] + pref[a - 1][b - 1];
    };
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (!is_hole[i][j]) {
                int l = 1, r = min(i, j);
                int add;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (count(i - mid + 1, j - mid + 1, i, j) == 0) {
                        add = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[i][j] += add;
            }
        }
    }
    cout << dp[h][w] << '\n';
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