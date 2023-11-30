#include "../inc.h"

class Solution {
   public:
    int goodNodes(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().goodNodes(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({2, null, 4, 10, 8, null, null, 4}, 4);
    test({3, 1, 4, 3, null, 1, 5}, 4);
    test({3, 3, null, 4, 2}, 3);
    test({1}, 1);
    return 0;
}
