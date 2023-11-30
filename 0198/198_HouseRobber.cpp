#include "../inc.h"

class Solution {
   public:
    int rob(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().rob(nums));
}

int main() {
    test({0}, 0);
    test({1, 2, 3, 1}, 4);
    test({2, 7, 9, 3, 1}, 12);
    test({2, 1, 1, 2}, 4);
    return 0;
}
