#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return helper(nums, 0, nums.size());
    }
    TreeNode* helper(const vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    Solution so;
    auto ret = so.sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retval;
    treeToComplexValLevelOrder(ret, retval);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(expect);
        print(retval);
        print();
    }
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    return 0;
}
