#include "../inc.h"

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    auto p1 = nums;
    Solution so;
    auto ret = so.lengthOfLIS(nums);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({1, 3, 6, 7, 9, 4, 10, 5, 6}, 6);
    test({10, 9, 2, 5, 3, 7, 101, 18}, 4);
    test({0, 1, 0, 3, 2, 3}, 4);
    test({7, 7, 7, 7, 7, 7, 7}, 1);
    return 0;
}