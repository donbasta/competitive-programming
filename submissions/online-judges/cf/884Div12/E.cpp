class Solution {
   public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> op(n - k + 1);
        op[0] = nums[0];
        for (int i = 1; i <= n - k; i++) {
            int tmp = nums[i] - nums[i - 1];
            if (i >= k) tmp += op[i - k];
            if (tmp < 0) return false;
            op[i] = tmp;
        }
        for (auto e : op) cout << e << ' ';
        cout << '\n';
        cout << "HAHA\n";
        int cur = 0;
        for (int i = n - 1; i >= n - k + 1; i--) {
            if (i - k + 1 >= 0) cur += op[i - k + 1];
            cout << cur << '\n';
            if (cur != nums[i]) return false;
        }
        return true;
    }
};