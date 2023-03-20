#include "../inc/inc.h"

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, bool expect) {
    Solution so;
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = so.isSymmetric(root);
    if (expect == ret) {
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
    test({1, 2, 3}, false);
    test({1, 2, 2, 3, 4, 4, 3}, true);
    test({1, 2, 2, null, 3, null, 3}, false);
    return 0;
}