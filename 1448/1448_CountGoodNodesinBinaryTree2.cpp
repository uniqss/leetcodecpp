#include "../inc.h"

class Solution {
   public:
    int goodNodes(TreeNode* root) { return helper(root, INT_MIN); }
    int helper(TreeNode* root, int vmax) {
        int ret = 0;
        if (root == nullptr) return ret;
        if (root->val >= vmax) ++ret;
        ret += helper(root->left, max(vmax, root->val));
        ret += helper(root->right, max(vmax, root->val));
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.goodNodes(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({2, null, 4, 10, 8, null, null, 4}, 4);
    test({3, 1, 4, 3, null, 1, 5}, 4);
    test({3, 3, null, 4, 2}, 3);
    test({1}, 1);
    return 0;
}
