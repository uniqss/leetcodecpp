#include "../inc.h"

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().maxSubarraySumCircular(nums));
}

int main() {
    test({4, 4, -9, 2, 1, 7, 5}, 23);
    test({2, -2, 2, 7, 8, 0}, 19);
    test({-2, 4, -5, 4, -5, 9, 4}, 15);
    test({1, -6, -7, 4}, 5);
    test({9, -4, -7, 9}, 18);
    test({3, -1, 2, -1}, 4);
    test({1, -2, 3, -2}, 3);
    test({5, -3, 5}, 10);
    test({-3, -2, -3}, -2);
    return 0;
}
