#include "../inc.h"

class Solution {
   public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.countNodes(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3, 4, 5, 6}, 6);
    test({}, 0);
    test({1}, 1);
    return 0;
}