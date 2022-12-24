// https://cp-algorithms.com/dynamic_programming/knuth-optimization.html#generic-implementation

// conditions:
// dp[i][j] = min(dp[i][k] + dp[k + 1][j] + C(i, j)), k \in [i, j)
// the best k is called opt(i, j)
// the following must hold: opt(i, j-1) <= opt(i, j) <= opt(i+1, j), which is equivalent with:
// for a <= b <= c <= d:
// C(b, c) <= C(a, d), and
// C(a, c) + C(b, d) <= C(a, d) + C(b, c) (quadrangle ineq)

auto C = [&](int i, int j) -> ll {
    // compute cost function C
}

                              const ll INF = 1e18;

void KnuthOptimizationDP(vector<vector<int>> &dp) {
    int n = dp.size();
    for (int i = 0; i < n; i++) {
        opt[i][i] = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ll mn = INF;
            ll cost = C(i, j);
            for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                if (mn >= dp[i][k] + dp[k + 1][j] + cost) {
                    mn = dp[i][k] + dp[k + 1][j] + cost;
                    opt[i][j] = k;
                }
            }
            dp[i][j] = mn;
        }
    }
}
