#include "../inc.h"

class Solution {
   public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        int ret = 0;
        if (root->left) ret = max(ret, helper(root->left, true, 1));
        if (root->right) ret = max(ret, helper(root->right, false, 1));
        return ret;
    }
    int helper(TreeNode* root, bool left, int zig) {
        int ret = zig;
        if (left && root->right) ret = max(ret, helper(root->right, false, zig + 1));
        if (!left && root->left) ret = max(ret, helper(root->left, true, zig + 1));
        if (left && root->left) ret = max(ret, helper(root->left, true, 1));
        if (!left && root->right) ret = max(ret, helper(root->right, false, 1));
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.longestZigZag(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1}, 3);
    test({1, 1, 1, null, 1, null, null, 1, 1, null, 1}, 4);
    test({1}, 0);
    return 0;
}
