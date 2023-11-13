#include "../inc.h"

class Solution {
    int ret;

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        ret = 0;
        if (root == nullptr) return ret;
        helper(root);
        return ret;
    }
    int helper(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return 0;
        int l = root->left != nullptr ? helper(root->left) + 1 : 0;
        int r = root->right != nullptr ? helper(root->right) + 1 : 0;
        ret = max(ret, l + r);
        return max(l, r);
    }
};

void test(vector<ComplexVal>&& vals, int expect) {
    auto p1 = vals;
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.diameterOfBinaryTree(root);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({1, 2, 3, 4, 5}, 3);
    test({1, 2}, 1);
    return 0;
}