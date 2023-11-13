#include "../inc.h"

class Solution {
   public:
    // todo@uniqs 学习一下线段树这个数据结构
    int maxSubArray(vector<int>& nums) {}
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
