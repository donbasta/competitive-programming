#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using ll = long long;

struct SparseTableAnd {
    const int K = 20;
    vector<vector<int>> table;
    int n;
    SparseTableAnd(const vector<int>& ar) : n(ar.size()) {
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = (table[i - 1][j] & table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return (table[i][l] & table[i][r - (1 << i) + 1]);
    }
};

struct SparseTableMin {
    const int K = 20;
    vector<vector<ll>> table;
    int n;
    SparseTableMin(const vector<ll>& ar) : n(ar.size()) {
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    void build(const vector<ll>& ar) {
        n = ar.size();
        table.clear();
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    ll get(int l, int r) {
        const ll INF = 2e9;
        if (r < l) return INF;
        int i = bit_width(r - l + 1) - 1;
        return min(table[i][l], table[i][r - (1 << i) + 1]);
    }
};

class Solution {
   public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        const ll INF = 2e9;
        int m = andValues.size();
        int n = nums.size();

        vector<vector<ll>> dp(m + 1, vector<ll>(n, INF));

        SparseTableAnd st(nums);
        for (int i = 0; i < n; i++) {
            if (st.get(0, i) == andValues[0]) {
                dp[1][i] = nums[i];
            }
        }
        SparseTableMin ft(dp[1]);

        for (int i = 2; i <= m; i++) {
            for (int j = i - 1; j < n; j++) {
                int need = andValues[i - 1];
                // dp[j][i] = ar[j] + min(dp[k][i - 1]), where ar[k + 1] & ... & ar[j] = andValues[i - 1]
                int L = -1, R = -1;
                {
                    int lo = 0, hi = j;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (st.get(mid, j) < need) {
                            lo = mid + 1;
                        } else {
                            L = mid;
                            hi = mid - 1;
                        }
                    }
                }
                {
                    int lo = 0, hi = j;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (st.get(mid, j) > need) {
                            hi = mid - 1;
                        } else {
                            R = mid;
                            lo = mid + 1;
                        }
                    }
                }
                // cout << "LR " << L << ' ' << R << ' ' << j << ' ' << i << '\n';
                if (L == -1 || R == -1) {
                    // assert(L == -1 && R == -1);
                    continue;
                } else {
                    // int mn = ft.get(max(0, L - 1), R - 1);
                    cerr << i << ' ' << j << ' ' << dp[i][j] << ' ' << nums[j] << '\n';
                    dp[i][j] = nums[j];
                    // if (1ll * mn < INF) {
                    //     // dp[i][j] = nums[j];
                    //     dp[i][j] = nums[j] + mn;
                    // }
                }
            }
            // ft.build(dp[i]);
        }
        return 0;
        return (dp[m][n - 1] >= INF ? -1 : dp[n - 1][m]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), andd(m);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < m; i++) cin >> andd[i];
    cout << Solution().minimumValueSum(nums, andd) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}