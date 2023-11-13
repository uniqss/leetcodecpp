#include "../inc.h"

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, bool expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().isSymmetric(root));
}

int main() {
    test({2, 3, 3, 4, 5, 5, 4, null, null, 8, 9, null, null, 9, 8}, false);
    test({1, 2, 3}, false);
    test({1, 2, 2, 3, 4, 4, 3}, true);
    test({1, 2, 2, null, 3, null, 3}, false);
    return 0;
}