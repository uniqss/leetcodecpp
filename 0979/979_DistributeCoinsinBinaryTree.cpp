#include "../inc.h"

class Solution {
   public:
    int distributeCoins(TreeNode* root) {}
};

void test(const vector<int>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.distributeCoins(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({3, 0, 0}, 2);
    test({0, 3, 0}, 3);
    return 0;
}
