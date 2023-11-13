#include "../inc.h"

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().firstMissingPositive(nums));
}

int main() {
    test({1, 1}, 2);
    test({1, 2, 0}, 3);
    test({3, 4, -1, 1}, 2);
    test({7, 8, 9, 11, 12}, 1);
    return 0;
}
