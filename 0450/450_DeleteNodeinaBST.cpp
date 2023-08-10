#include "../inc.h"

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {}
};

void test(const vector<ComplexVal>& vals, int key, const vector<ComplexVal>& expect) {
    TreeNode* root = constructIntTree(vals);
    Solution so;
    auto ret = so.deleteNode(root, key);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    assert_eq_ret(expect, retvals);
    print(vals);
    print(key);
}

int main() {
    test({5, 3, 6, 2, 4, null, 7}, 5, {6, 3, 7, 2, 4});
    test({5, 3, 6, 2, 4, null, 7}, 3, {5, 4, 6, 2, null, null, 7});
    test({5, 3, 6, 2, 4, null, 7}, 0, {5, 3, 6, 2, 4, null, 7});
    test({}, 0, {});
    return 0;
}
