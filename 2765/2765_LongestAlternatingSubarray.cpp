#include "../inc.h"

class Solution {
   public:
    int alternatingSubarray(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().alternatingSubarray(nums));
}
int main() {
    test({2, 3, 4, 3, 4}, 4);
    test({4, 5, 6}, 2);
    return 0;
}