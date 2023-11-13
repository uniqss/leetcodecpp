#include "../inc.h"

class Solution {
   public:
    int getMinimumDifference(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.getMinimumDifference(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 2, 6, 1, 3}, 1);
    test({1, 0, 48, null, null, 12, 49}, 1);
    return 0;
}
