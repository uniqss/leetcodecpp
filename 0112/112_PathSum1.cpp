#include "../inc.h"

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) { return helper(root, 0, targetSum); }
    bool helper(TreeNode* root, int sum, int target) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return sum + root->val == target;
        sum += root->val;
        return helper(root->left, sum, target) || helper(root->right, sum, target);
    }
};

void test(const vector<ComplexVal>& vals, int targetsum, bool expect) {
    save4print(vals);
    save4print(targetsum);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.hasPathSum(root, targetsum);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2}, 1, false);
    test({}, 0, false);
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, 22, true);
    test({1, 2, 3}, 5, false);

    return 0;
}
