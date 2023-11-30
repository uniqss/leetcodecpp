#include "../inc.h"

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().productExceptSelf(nums));
}

int main() {
    test({1, 2, 3, 4}, {24, 12, 8, 6});
    test({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    return 0;
}
