#include "../inc.h"


class Solution {
   public:
    bool isBalanced(TreeNode* root) {
        int d = getDepth(root);
        return d != -1;
    }
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int dleft = getDepth(root->left);
        if (dleft == -1) return -1;
        int dright = getDepth(root->right);
        if (dright == -1) return -1;
        if (abs(dleft - dright) > 1) return -1;
        return max(dleft, dright) + 1;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    save4print(vals);
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().isBalanced(root));
}

int main() {
    test({1, null, 2, null, 3}, false);
    test({1, 2, 3, 4, 5, 6, null, 8}, true);
    test({3, 9, 20, null, null, 15, 7}, true);
    test({1, 2, 2, 3, 3, null, null, 4, 4}, false);
    return 0;
}