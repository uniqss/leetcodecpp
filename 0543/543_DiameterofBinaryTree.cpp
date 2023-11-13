#include "../inc.h"

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {}
};

void test(vector<ComplexVal>&& vals, int expect) {
    auto p1 = vals;
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.diameterOfBinaryTree(root);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({1, 2, 3, 4, 5}, 3);
    test({1, 2}, 1);
    return 0;
}