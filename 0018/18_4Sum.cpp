#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {}
};

void test(vector<int>&& nums, int target, vector<vector<int>>&& expect) {
    save4print(nums, target);
    auto ret = Solution().fourSum(nums, target);
    sortvvrawInnerAndOuter(expect);
    sortvvrawInnerAndOuter(ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    test({2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});
    return 0;
}
