#include "../inc.h"

class Solution {
   public:
    int goodNodes(TreeNode* root) { return helper(root, root->val, 0); }
    int helper(TreeNode* root, int vmax, int count) {
        if (root->val >= vmax) ++count;
        if (root->left == nullptr && root->right == nullptr) return count;
        int l = 0, r = 0;
        if (root->left != nullptr) l = helper(root->left, max(vmax, root->val), 0);
        if (root->right != nullptr) r = helper(root->right, max(vmax, root->val), 0);
        return count + l + r;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().goodNodes(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({2, null, 4, 10, 8, null, null, 4}, 4);
    test({3, 1, 4, 3, null, 1, 5}, 4);
    test({3, 3, null, 4, 2}, 3);
    test({1}, 1);
    return 0;
}
