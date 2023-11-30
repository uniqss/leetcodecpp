#include "../inc.h"

class Solution {
   public:
    int longestZigZag(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().longestZigZag(root));
}

int main() {
    test({1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1}, 3);
    test({1, 1, 1, null, 1, null, null, 1, 1, null, 1}, 4);
    test({1}, 0);
    return 0;
}
