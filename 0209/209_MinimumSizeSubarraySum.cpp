#include "../inc.h"

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {}
};

void test(int target, vector<int>&& nums, int expect) {
    save4print(target, nums);
    assert_eq_ret(expect, Solution().minSubArrayLen(target, nums));
}

int main() {
    test(7, {2, 3, 1, 2, 4, 3}, 2);
    test(4, {1, 4, 4}, 1);
    test(11, {1, 1, 1, 1, 1, 1, 1, 1}, 0);
    return 0;
}
