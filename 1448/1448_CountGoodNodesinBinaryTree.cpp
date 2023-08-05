#include "../inc.h"

class Solution {
   public:
    int goodNodes(TreeNode* root) {}
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
