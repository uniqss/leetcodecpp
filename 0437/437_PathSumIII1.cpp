#include "../inc.h"

class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
    // 以root为起点，且包含root的所有解
    int rootSum(TreeNode* root, int64_t targetSum) {
        if (root == nullptr) return 0;
        int ret = 0;
        if (root->val == targetSum) ++ret;
        targetSum -= root->val;
        ret += rootSum(root->left, targetSum);
        ret += rootSum(root->right, targetSum);
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int targetSum, int expect) {
    save4print(vals, targetSum);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().pathSum(root, targetSum));
}

int main() {
    test({}, 1, 0);
    test({4, 2, 6}, 6, 2);
    test({10, 5, -3, 3, 2, null, 11, 3, -2, null, 1}, 8, 3);
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1}, 22, 3);
    return 0;
}
