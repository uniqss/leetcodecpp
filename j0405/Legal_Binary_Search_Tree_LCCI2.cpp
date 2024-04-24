#include "../inc.h"

class Solution {
   public:
    bool isValidBST(TreeNode* root) { return helper(root, INT64_MIN, INT64_MAX); }
    bool helper(TreeNode* root, int64_t vmin, int64_t vmax) {
        if (root == nullptr) return true;
        if (root->val <= vmin || root->val >= vmax) return false;
        return helper(root->left, vmin, root->val) && helper(root->right, root->val, vmax);
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    assert_eq_ret(expect, Solution().isValidBST(root));
}

int main() {
    test({2147483647}, true);
    test({1, 1}, false);
    test({2, 1, 3}, true);
    test({5, 1, 4, null, null, 3, 6}, false);
    return 0;
}
