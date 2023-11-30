#include "../inc.h"

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ret = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1), ret = max(ret, dp[i]);
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().lengthOfLIS(nums));
}

int main() {
    test({1, 3, 6, 7, 9, 4, 10, 5, 6}, 6);
    test({10, 9, 2, 5, 3, 7, 101, 18}, 4);
    test({0, 1, 0, 3, 2, 3}, 4);
    test({7, 7, 7, 7, 7, 7, 7}, 1);
    return 0;
}