#include "../inc.h"

class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {}
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
