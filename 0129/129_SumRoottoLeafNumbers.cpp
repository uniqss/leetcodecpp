#include "../inc.h"

class Solution {
   public:
    int sumNumbers(TreeNode* root) {}
};

void test(const vector<int>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.sumNumbers(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3}, 25);
    test({4, 9, 0, 5, 1}, 1026);
    return 0;
}
