#include "../inc.h"

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == right) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        if (!helper(left->left, right->right)) return false;
        if (!helper(left->right, right->left)) return false;
        return true;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().isSymmetric(root));
}

int main() {
    test({1, 2, 3}, false);
    test({1, 2, 2, 3, 4, 4, 3}, true);
    test({1, 2, 2, null, 3, null, 3}, false);
    return 0;
}