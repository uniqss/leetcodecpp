#include "../inc.h"

class Solution {
    int ret = 0;

   public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        helper(root, 0);
        return ret;
    }
    void helper(TreeNode* root, int parentsum) {
        parentsum = parentsum * 10 + root->val;
        if (root->left) helper(root->left, parentsum);
        if (root->right) helper(root->right, parentsum);
        if (root->left == nullptr && root->right == nullptr) ret += parentsum;
    }
};

void test(const vector<int>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().sumNumbers(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3}, 25);
    test({4, 9, 0, 5, 1}, 1026);
    return 0;
}
