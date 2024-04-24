#include "../inc.h"

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int vmax = INT_MIN, n = nums.size(), sum = 0;
        for (int d : nums) sum += d, vmax = max(vmax, d);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        if (vmax > target) return false;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            int ni = nums[i];
            for (int j = 1; j <= target; ++j) {
                if (ni == j) {
                    dp[i][j] = true;
                } else if (ni > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - ni];
                }
            }
        }
        return dp[n - 1][target];
    }
};

void test(vector<int>&& nums, bool expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().canPartition(nums));
}

int main() {
    test({1, 2, 5}, false);
    test({1, 5, 11, 5}, true);
    test({1, 2, 3, 5}, false);
    return 0;
}
