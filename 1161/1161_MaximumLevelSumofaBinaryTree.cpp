#include "../inc.h"

class Solution {
   public:
    int maxLevelSum(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().maxLevelSum(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 7, 0, 7, -8, null, null}, 2);
    test({989, null, 10250, 98693, -89388, null, null, null, -32127}, 2);
    return 0;
}
