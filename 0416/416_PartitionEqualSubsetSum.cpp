#include "../inc.h"

class Solution {
   public:
    bool canPartition(vector<int>& nums) {}
};

void test(vector<int>&& nums, bool expect) {
    auto p1 = nums;
    Solution so;
    auto ret = so.canPartition(nums);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({1, 2, 5}, false);
    test({1, 5, 11, 5}, true);
    test({1, 2, 3, 5}, false);
    return 0;
}
