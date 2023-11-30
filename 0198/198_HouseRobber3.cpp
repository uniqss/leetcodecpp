#include "../inc.h"

// 最最最传统质朴的dp，纯天然无污染，没做过美容手术的
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_robcurr(n + 2, 0);
        vector<int> dp_nocurr(n + 2, 0);
        for (int i = 2; i <= n + 1; ++i) {
            dp_robcurr[i] = max(dp_robcurr[i - 2] + nums[i - 2], dp_nocurr[i - 1] + nums[i - 2]);
            dp_nocurr[i] = max(dp_robcurr[i - 1], dp_nocurr[i - 1]);
        }
        return max(dp_robcurr[n + 1], dp_nocurr[n + 1]);
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().rob(nums));
}

int main() {
    test({0}, 0);
    test({1, 2, 3, 1}, 4);
    test({2, 7, 9, 3, 1}, 12);
    test({2, 1, 1, 2}, 4);
    return 0;
}
