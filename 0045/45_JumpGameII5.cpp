#include "../inc.h"

// dp 的标准做法
class Solution {
   public:
    int jump(vector<int>& nums) {
        int nsize = nums.size();
        vector<int> dp(nsize, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nsize; ++i) {
            for (int idx = i + 1; idx <= i + nums[i] && idx < nsize; ++idx) {
                dp[idx] = min(dp[idx], dp[i] + 1);
            }
        }

        return dp[nsize - 1];
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().jump(nums));
}

int main() {
    test({2, 3, 1, 1, 4}, 2);
    test({2, 3, 0, 1, 4}, 2);
    return 0;
}
