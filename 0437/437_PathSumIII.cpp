#include "../inc.h"

class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {}
};

void test(const vector<ComplexVal>& vals, int targetSum, int expect) {
    save4print(vals, targetSum);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().pathSum(root, targetSum));
}

int main() {
    test({1, -2, -3}, -1, 1);
    test({1}, 0, 0);
    test({}, 1, 0);
    test({4, 2, 6}, 6, 2);
    test({10, 5, -3, 3, 2, null, 11, 3, -2, null, 1}, 8, 3);
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1}, 22, 3);
    return 0;
}
