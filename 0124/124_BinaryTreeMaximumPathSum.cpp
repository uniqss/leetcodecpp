#include "../inc.h"

class Solution {
   public:
    int maxPathSum(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().maxPathSum(root));
}

int main() {
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, 48);
    test({2, -1, -2}, 2);
    test({1, -2, -3, 1, 3, -2, null, -1}, 3);
    test({-3}, -3);
    test({1, 2, 3}, 6);
    test({-10, 9, 20, null, null, 15, 7}, 42);
    return 0;
}