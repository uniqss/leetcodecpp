#include "../inc.h"

class Solution {
   public:
    bool isValidBST(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, bool expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    assert_eq_ret(expect, Solution().isValidBST(root));
}

int main() {
    test({2147483647}, true);
    test({1, 1}, false);
    test({2, 1, 3}, true);
    test({5, 1, 4, null, null, 3, 6}, false);
    return 0;
}
