#include "../inc.h"

/*
反向思考，如果把中间最小的和算出来，会怎样
实质上的出发点是，最大和为正／最大和为负
最大和为负只有一种可能：全负
只要哪怕有一个正数或０，最大和都非负 sum - smin的意义要么就是正数＋一段负(非负居中)，要么就是那个正数(非负靠边)
*/
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), premax = nums[0], premin = nums[0], smax = nums[0], smin = nums[0], sum = nums[0];
        for (int i = 1; i < n; ++i) {
            premax = max(premax + nums[i], nums[i]);
            smax = max(smax, premax);
            premin = min(premin + nums[i], nums[i]);
            smin = min(smin, premin);
            sum += nums[i];
        }
        if (smax < 0) {
            return smax;
        } else {
            return max(smax, sum - smin);
        }
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().maxSubarraySumCircular(nums));
}

int main() {
    test({-2, 4, -5, 4, -5, 9, 4}, 15);
    test({1, -6, -7, 4}, 5);
    test({9, -4, -7, 9}, 18);
    test({3, -1, 2, -1}, 4);
    test({1, -2, 3, -2}, 3);
    test({5, -3, 5}, 10);
    test({-3, -2, -3}, -2);
    return 0;
}
