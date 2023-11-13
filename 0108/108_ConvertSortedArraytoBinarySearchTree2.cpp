#include "../inc.h"

// 本质 上是一样的，只是[]与[)的细微差异
class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() - 1;
        TreeNode* ret = helper(nums, 0, n);
        return ret;
    }
    TreeNode* helper(const vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int x = (l + r) / 2;
        TreeNode* curr = new TreeNode(nums[x], nullptr, nullptr);
        if (x > l) curr->left = helper(nums, l, x - 1);
        if (x < r) curr->right = helper(nums, x + 1, r);
        return curr;
    }
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    save4print(nums, expect);
    auto p1 = nums;
    auto ret = Solution().sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    vector<int> retvalsi;
    vcomplexFilterInt(retvals, retvalsi);
    sort(retvalsi.begin(), retvalsi.end());
    bool isbst = treeIsBST(ret);
    assert_retnone(p1 == retvalsi && isbst);
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    test({1, 3}, {3, 1});
    return 0;
}
