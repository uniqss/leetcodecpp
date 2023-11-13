#include "../inc.h"

class Solution {
   public:
    int maxDepth(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expected) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expected, Solution().maxDepth(root));
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 3);
    test({1, null, 2}, 2);
    test({1, 2}, 2);
    test({}, 0);

    return 0;
}

/*
[3,9,20,null,null,15,7]
[1,null,2]
3
2
*/
