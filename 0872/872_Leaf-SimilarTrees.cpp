#include "../inc.h"

class Solution {
   public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {}
};

void test(const vector<ComplexVal>& v1, const vector<ComplexVal>& v2, bool expect) {
    save4print(v1, v2);
    TreeNode *root1 = constructIntTree(v1), *root2 = constructIntTree(v2);
    TreeAutoReleaser _(root1, root2);
    auto ret = Solution().leafSimilar(root1, root2);
    assert_eq_ret(expect, ret);
}

int main() {
    test({3, 5, 1, 6, 2, 9, 8, null, null, 7, 4}, {3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8},
         true);
    test({1, 2, 3}, {1, 3, 2}, false);
    return 0;
}
