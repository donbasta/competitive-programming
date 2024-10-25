#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n;
    vector<int> A(n + 1);
    unordered_map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cin >> m;
    vector<int> B(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
        pos[B[i]].push_back(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> bt(n + 1, vector<pair<int, int>>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = 1;
                for (int k = 1; k < i; k++) {
                    if (A[k] >= A[i]) continue;
                    if (!pos.count(A[k])) continue;
                    int idx = upper_bound(pos[A[k]].begin(), pos[A[k]].end(), j) - pos[A[k]].begin();
                    if (idx == 0) continue;
                    --idx;
                    int posB = pos[A[k]][idx];
                    if (1 + dp[k][posB] > dp[i][j]) {
                        dp[i][j] = 1 + dp[k][posB];
                        bt[i][j] = make_pair(k, posB);
                    }
                }
            }
        }
    }

    int ans = 0;
    int ci = 0, cj = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] > ans) {
                ans = dp[i][j];
                ci = i, cj = j;
            }
        }
    }
    cout << ans << '\n';
    vector<int> lcis;
    while (ci > 0 && cj > 0) {
        lcis.push_back(A[ci]);
        int ti = bt[ci][cj].first, tj = bt[ci][cj].second;
        ci = ti, cj = tj;
    }
    reverse(lcis.begin(), lcis.end());
    assert(lcis.size() == ans);
    for (int i = 0; i < ans; i++) {
        cout << lcis[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}