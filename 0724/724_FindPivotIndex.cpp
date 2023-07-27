#include "../inc.h"

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.pivotIndex(nums);
    assert_eq_ret(expect, ret);
    print(nums_param);
}

int main() {
    test({1, 7, 3, 6, 5, 6}, 3);
    test({1, 2, 3}, -1);
    test({2, 1, -1}, 0);
    return 0;
}
