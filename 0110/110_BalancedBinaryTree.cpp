#include "../inc.h"


class Solution {
   public:
    bool isBalanced(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, bool expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.isBalanced(root);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, null, 2, null, 3}, false);
    test({1, 2, 3, 4, 5, 6, null, 8}, true);
    test({3, 9, 20, null, null, 15, 7}, true);
    test({1, 2, 2, 3, 3, null, null, 4, 4}, false);
    return 0;
}