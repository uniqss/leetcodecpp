#include "../inc.h"

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {}
};

void test(const vector<ComplexVal>& vals, int val, const vector<ComplexVal>& expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.searchBST(root, val);
    if (expect.empty()) {
        assert_retnone(null == nullptr);
    } else {
        vector<ComplexVal> retvlas;
        treeToComplexValLevelOrder(ret, retvlas);
        assert_eq_ret(expect, retvlas);
    }
    print(vals);
    print(val);
}

int main() {
    test({4, 2, 7, 1, 3}, 2, {2, 1, 3});
    test({4, 2, 7, 1, 3}, 5, {});
    return 0;
}
