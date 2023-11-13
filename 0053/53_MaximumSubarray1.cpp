#include "../inc.h"

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], ret = sum, nsize = nums.size();
        for (int i = 1; i < nsize; ++i) {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            ret = max(ret, sum);
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
