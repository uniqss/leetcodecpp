#include "../inc.h"

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().longestSubarray(nums));
}

int main() {
    test({1, 1, 0, 0, 1, 1, 1, 0, 1}, 4);
    test({1, 1, 0, 1}, 3);
    test({0, 1, 1, 1, 0, 1, 1, 0, 1}, 5);
    test({1, 1, 1}, 2);
    return 0;
}
