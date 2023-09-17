#include "../inc.h"

class Solution {
    unordered_map<int64_t, int> sum2count;

   public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        sum2count[0] = 1;
        int ret = helper(root, 0, targetSum);
        return ret;
    }
    int helper(TreeNode* root, int64_t currSum, int targetSum) {
        int ret = 0;
        currSum += root->val;
        if (sum2count.count(currSum - targetSum) > 0) ret = sum2count[currSum - targetSum];
        ++sum2count[currSum];
        if (root->left) ret += helper(root->left, currSum, targetSum);
        if (root->right) ret += helper(root->right, currSum, targetSum);
        --sum2count[currSum];

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int targetSum, int expect) {
    TreeNode* root = constructIntTree(vals);
    Solution so;
    auto ret = so.pathSum(root, targetSum);
    assert_eq_ret(expect, ret);
    print(vals);
    print(targetSum);
}

int main() {
    test({4, 2, 6}, 6, 2);
    test({10, 5, -3, 3, 2, null, 11, 3, -2, null, 1}, 8, 3);
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1}, 22, 3);
    return 0;
}
