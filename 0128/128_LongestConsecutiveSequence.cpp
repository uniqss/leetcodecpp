#include "../inc.h"

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    Solution so;
    auto ret = so.longestConsecutive(nums);
    assert_eq_ret(expect, ret);
}

int main() {
    test({-6, 8, -5, 7, -9, -1, -7, -6, -9, -7, 5, 7, -1, -8, -8, -2, 0}, 5);
    test({100, 4, 200, 1, 3, 2}, 4);
    test({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9);
    return 0;
}
