#include "../inc.h"

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {}
};

void test(const vector<ComplexVal>& vals, vector<string>&& expect) {
    sort(expect.begin(), expect.end());
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.binaryTreePaths(root);
    sort(ret.begin(), ret.end());
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        pvraw(expect);
        pvraw(ret);
    }
}

int main() {
    test({1, 2, 3, null, 5}, {"1->2->5", "1->3"});
    test({1}, {"1"});
    return 0;
}