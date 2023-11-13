#include "../inc.h"

// 官方题解，本质上和1一样，看起来更赏心悦目一点，是从dp直接脱胎换骨过来的
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ret = nums[0];
        for (int n : nums) {
            pre = max(pre + n, n);
            ret = max(ret, pre);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().maxSubArray(nums));
}

int main() {
    test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    test({1}, 1);
    test({5, 4, -1, 7, 8}, 23);
    return 0;
}
