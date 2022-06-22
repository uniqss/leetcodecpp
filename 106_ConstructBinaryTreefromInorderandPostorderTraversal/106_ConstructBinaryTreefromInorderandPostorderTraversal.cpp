#include "../inc.h"

class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {}
};

void test(vector<int>&& inorder, vector<int>&& postorder, const vector<ComplexVal>& expect) {
    Solution so;
    auto ret = so.buildTree(inorder, postorder);
    TreeAutoReleaser _1(ret);
    auto etree = constructIntTree(expect);
    TreeAutoReleaser _2(etree);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    vector<int> expect_vec;
    treeToIntVecLevelOrder(etree, expect_vec);
    if (ret_vec == expect_vec) {
        praw("ok");
    } else {
        praw("not ok");
        pvraw(inorder);
        pvraw(postorder);
        pvcomplex(expect);
        pTree(etree);
        pTree(ret);
        pnewline();
    }
}

int main() {
    test({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    return 0;
}