#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().zigzagLevelOrder(root));
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {{4}, {6, 2}, {1, 3, 5, 7}});
    test({3, 9, 20, null, null, 15, 7}, {{3}, {20, 9}, {15, 7}});
    test({1}, {{1}});
    test({}, {});
    return 0;
}
