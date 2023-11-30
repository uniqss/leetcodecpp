#include "../inc.h"

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {}
};

void test(const vector<ComplexVal>& vals, int key, const vector<ComplexVal>& expect) {
    save4print(vals, key);
    TreeNode* root = constructIntTree(vals);
    auto ret = Solution().deleteNode(root, key);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({5, 3, 6, 2, 4, null, 7}, 5, {6, 3, 7, 2, 4});
    test({5, 3, 6, 2, 4, null, 7}, 3, {5, 4, 6, 2, null, null, 7});
    test({5, 3, 6, 2, 4, null, 7}, 0, {5, 3, 6, 2, 4, null, 7});
    test({}, 0, {});
    return 0;
}
