#include "../inc.h"

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {}
};

void test(vector<int>&& nums, bool expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.increasingTriplet(nums);
    assert_eq_ret(expect, ret);
    print(nums_param);
}

int main() {
    test({20, 100, 10, 12, 5, 13}, true);
    test({2, 4, -2, -3}, false);
    test({1, 2, 3, 4, 5}, true);
    test({5, 4, 3, 2, 1}, false);
    test({2, 1, 5, 0, 4, 6}, true);
    return 0;
}
