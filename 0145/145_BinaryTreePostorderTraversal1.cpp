#include "../inc.h"

// recursive
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        helper(root, ret);
        return ret;
    }
    void helper(TreeNode* root, vector<int>& ret) {
        if (root == nullptr) return;
        if (root->left != nullptr) helper(root->left, ret);
        if (root->right != nullptr) helper(root->right, ret);
        ret.push_back(root->val);
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);
    assert_eq_ret(expect, Solution().postorderTraversal(tree));
}

int main() {
    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});
    return 0;
}
