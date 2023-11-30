#include "../inc.h"

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().rightSideView(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3, null, 5, null, 4}, {1, 3, 4});
    test({1, null, 3}, {1, 3});
    test({}, {});
    return 0;
}
