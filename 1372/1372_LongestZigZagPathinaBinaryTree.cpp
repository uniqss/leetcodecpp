#include "../inc.h"

class Solution {
   public:
    int longestZigZag(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.longestZigZag(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1}, 3);
    test({1, 1, 1, null, 1, null, null, 1, 1, null, 1}, 4);
    test({1}, 0);
    return 0;
}
