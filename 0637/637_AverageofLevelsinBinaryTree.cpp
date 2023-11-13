#include "../inc.h"

class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, const vector<double>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.averageOfLevels(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({2147483647, 2147483647, 2147483647}, {2147483647, 2147483647});
    test({3, 9, 20, null, null, 15, 7}, {3.00000, 14.50000, 11.00000});
    test({3, 9, 20, 15, 7}, {3.00000, 14.50000, 11.00000});

    return 0;
}