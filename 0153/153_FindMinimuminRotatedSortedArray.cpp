#include "../inc.h"

class Solution {
   public:
    int findMin(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    auto p1 = nums;
    Solution so;
    auto ret = so.findMin(nums);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({3, 4, 5, 1, 2}, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    test({11, 13, 15, 17}, 11);
    return 0;
}