#include "../inc/inc.h"

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.levelOrder(root);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {{4}, {2, 6}, {1, 3, 5, 7}});
    test({3, 9, 20, null, null, 15, 7}, {{3}, {9, 20}, {15, 7}});
    test({1}, {{1}});
    test({}, {});
    return 0;
}
