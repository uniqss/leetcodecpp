#include "../inc.h"

class Solution {
   public:
    string smallestFromLeaf(TreeNode* root) {}
};

void test(vector<ComplexVal>&& vals, const string& expect) {
    save4print(vals, expect);
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().smallestFromLeaf(root));
}

int main() {
    test({0, 1, 2, 3, 4, 3, 4}, "dba");
    test({25, 1, 3, 1, 3, 0, 2}, "adz");
    test({2, 2, 1, null, 1, 0, null, 0}, "abc");
    return 0;
}
