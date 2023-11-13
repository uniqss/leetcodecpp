#include "../inc.h"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {}
};

void test(const vector<ComplexVal>& vp, const vector<ComplexVal>& vq, bool expect) {
    save4print(vp, vq);
    TreeNode* p = constructIntTree(vp);
    TreeNode* q = constructIntTree(vq);
    TreeAutoReleaser _(p, q);
    assert_eq_ret(expect, Solution().isSameTree(p, q));
}

int main() {
    test({}, {}, true);
    test({1, 2, 3}, {1, 2, 3}, true);
    test({1, 2}, {1, null, 2}, false);
    return 0;
}
