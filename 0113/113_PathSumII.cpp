#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {}
};

void test(const vector<ComplexVal>& vals, int targetsum, vector<vector<int>>&& expect) {
    save4print(vals, targetsum);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().pathSum(root, targetsum);
    sortvvrawInnerAndOuter(expect, ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test({}, 0, {});
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1}, 22, {{5, 4, 11, 2}, {5, 8, 4, 5}});
    test({1, 2, 3}, 5, {});

    return 0;
}
