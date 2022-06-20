#include "../inc.h"

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
        praw("ok");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({1, 2, 2, 3, 4, 4, 3}, true);
    test({1, 2, 2, null, 3, null, 3}, false);
    return 0;
}