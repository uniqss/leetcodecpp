#include "../inc.h"

class Solution {
    int64_t ret = INT_MAX;

   public:
    int getMinimumDifference(TreeNode* root) {
        if (root) helper(root, INT_MIN, INT_MAX);
        return (int)ret;
    }
    void helper(TreeNode* root, int64_t vleft, int64_t vright) {
        if (!root) return;
        ret = min(ret, root->val - vleft);
        ret = min(ret, vright - root->val);
        if (root->left) helper(root->left, vleft, root->val);
        if (root->right) helper(root->right, root->val, vright);
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.getMinimumDifference(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 2, 6, 1, 3}, 1);
    test({1, 0, 48, null, null, 12, 49}, 1);
    return 0;
}
