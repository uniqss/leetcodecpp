#include "../inc.h"

class Solution {
   public:
    bool isBalanced(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, bool expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().isBalanced(root));
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, true);
    test({1, 2, 2, 3, 3, null, null, 4, 4}, false);
    return 0;
}
