#include "../inc.h"

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val == val) return root;
            if (root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }
};

void test(const vector<ComplexVal>& vals, int val, const vector<ComplexVal>& expect) {
    save4print(vals, val);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().searchBST(root, val);
    if (expect.empty()) {
        assert_retnone(null == nullptr);
    } else {
        vector<ComplexVal> retvlas;
        treeToComplexValLevelOrder(ret, retvlas);
        assert_eq_ret(expect, retvlas);
    }
}

int main() {
    test({4, 2, 7, 1, 3}, 2, {2, 1, 3});
    test({4, 2, 7, 1, 3}, 5, {});
    return 0;
}
