#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { return helper(nums, 0, nums.size()); }
    TreeNode* helper(const vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        auto mid = (left + right) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = helper(nums, left, mid);
        curr->right = helper(nums, mid + 1, right);
        return curr;
    }
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
