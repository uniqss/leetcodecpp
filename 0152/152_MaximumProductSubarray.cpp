#include "../inc.h"

class Solution {
   public:
    int maxProduct(vector<int>& nums) {}
};

void test(vector<int>&& nums, int exepct) {
    auto p1 = nums;
    Solution so;
    auto ret = so.maxProduct(nums);
    assert_eq_ret(exepct, ret);
    print(p1);
}

int main() {
    test({3, -1, 4}, 4);
    test({-2, 3, -4}, 24);
    test({-3, -1, -1}, 3);
    test({0}, 0);
    test({-2}, -2);
    test({2, 3, -2, 4}, 6);
    test({-2, 0, -1}, 0);
    return 0;
}