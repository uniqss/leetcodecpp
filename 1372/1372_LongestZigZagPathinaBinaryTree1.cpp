#include "../inc.h"

class Solution {
   public:
    int longestZigZag(TreeNode* root) { return helper(root, 0, 0); }
    int helper(TreeNode* root, int zl, int zr) {
        int ret = max(zl, zr);
        if (root->left) {
            auto l = helper(root->left, zr + 1, 0);
            ret = max(ret, l);
        }
        if (root->right) {
            auto r = helper(root->right, 0, zl + 1);
            ret = max(ret, r);
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().longestZigZag(root));
}

int main() {
    test({1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1}, 3);
    test({1, 1, 1, null, 1, null, null, 1, 1, null, 1}, 4);
    test({1}, 0);
    return 0;
}
