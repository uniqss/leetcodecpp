#include "../inc.h"

class Solution {
   public:
    int majorityElement(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expected) {
    save4print(nums);
    assert_eq_ret(expected, Solution().majorityElement(nums));
}

int main() {
    test({2, 2, 1, 3, 1, 1, 4, 1, 1, 5, 1, 1, 6}, 1);
    test({8, 8, 7, 7, 7}, 7);
    test({3, 2, 3}, 3);
    test({2, 2, 1, 1, 1, 2, 2}, 2);
    test({1}, 1);
    test({6, 5, 5}, 5);
    return 0;
}
