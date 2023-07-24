#include "../inc.h"

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<int>& expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.productExceptSelf(nums);
    assert_eq_ret(expect, ret);
    print(nums_param);
}

int main() {
    test({1, 2, 3, 4}, {24, 12, 8, 6});
    test({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    return 0;
}
