#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int sumOfPowers(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<int> se;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                se.insert(nums[j] - nums[i]);
            }
        }

        vector<int> sel;
        for (auto e : se) {
            sel.push_back(e);
        }
        int sz = sel.size();

        int ans = 0;
        for (int id = 0; id < sz; id++) {
            int pref = (id == 0 ? 0 : sel[id - 1]), now = sel[id];
            vector<vector<int>> dp(n, vector<int>(k + 1)), pd(n, vector<int>(k + 1));
            dp[0][0] = pd[0][0] = dp[0][1] = pd[0][1] = 1;
            int jj = 0;
            for (int i = 1; i < n; i++) {
                while (jj < i && nums[i] - nums[jj] >= now) jj++;
                dp[i][0] = pd[i][0] = 1;
                for (int j = 1; j <= k; j++) {
                    dp[i][j] = (jj >= 1 ? pd[jj - 1][j - 1] : (j == 1 ? 1 : 0));
                    pd[i][j] = (pd[i - 1][j] + dp[i][j]) % MOD;
                }
            }
            int tot = 0;

            for (int i = 0; i < n; i++) {
                tot = (tot + dp[i][k]) % MOD;
            }
            ans = (1ll * ans + 1ll * (now - pref) * tot) % MOD;
        }
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n;
        vector<int> ve(n);
        for (int i = 0; i < n; i++) {
            cin >> ve[i];
        }
        cin >> k;
        Solution sol;
        cout << sol.sumOfPowers(ve, k) << '\n';
    }
}