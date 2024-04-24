#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    save4print(nums);
    auto ret = Solution().sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retval;
    treeToComplexValLevelOrder(ret, retval);
    assert_eq_ret(expect, retval);
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    return 0;
}
