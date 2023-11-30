#include "../inc.h"

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().pivotIndex(nums));
}

int main() {
    test({1, 7, 3, 6, 5, 6}, 3);
    test({1, 2, 3}, -1);
    test({2, 1, -1}, 0);
    return 0;
}
