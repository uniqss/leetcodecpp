#include "../inc.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().singleNumber(nums));
}

int main() {
    test({-2, -2, 1, 1, 4, 1, 4, 4, -4, -2}, -4);
    test({2, 2, 3, 2}, 3);
    test({0, 1, 0, 1, 0, 1, 99}, 99);
    return 0;
}
