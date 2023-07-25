#include "../inc.h"

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, double expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.findMaxAverage(nums, k);
    assert_eq_ret(expect, ret);
    print(nums_param);
    print(k);
}

int main() {
    test({1, 12, -5, -6, 50, 3}, 4, 12.75000);
    test({5}, 1, 5.00000);
    return 0;
}
