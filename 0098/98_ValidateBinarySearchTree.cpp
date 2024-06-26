#include "../inc.h"

class Solution {
   public:
    bool isValidBST(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().isValidBST(root));
}

int main() {
    test({2, 1, 3}, true);
    test({5, 1, 4, null, null, 3, 6}, false);
    test({2147483647}, true);
    return 0;
}

/*
[2,1,3]
[5,1,4,null,null,3,6]
true
false
*/
