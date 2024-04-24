#include "../inc.h"

class Solution {
   public:
    bool isValidBST(TreeNode* root) { return helper(root, INT64_MIN, INT64_MAX); }
    bool helper(TreeNode* root, int64_t min, int64_t max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        if (!helper(root->left, min, root->val)) return false;
        if (!helper(root->right, root->val, max)) return false;
        return true;
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
