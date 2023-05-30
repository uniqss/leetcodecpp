#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { return helper(nums, 0, nums.size()); }
    // [)
    TreeNode* helper(const vector<int>& nums, int l, int r) {
        if (l >= r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = helper(nums, l, mid);
        curr->right = helper(nums, mid + 1, r);
        return curr;
    }
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    Solution so;
    auto nums_param = nums;
    auto ret = so.sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    if (retvals == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    test({1, 3}, {3, 1});
    return 0;
}
