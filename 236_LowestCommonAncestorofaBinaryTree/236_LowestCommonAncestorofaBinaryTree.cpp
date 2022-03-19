#include "../inc.h"

class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}
};

void test(vector<ComplexVal> &&vals, int vp, int vq, int vexpect) {
    TreeNode *root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode *p = treeFindUniqueNodeByVal(root, vp);
    TreeNode *q = treeFindUniqueNodeByVal(root, vq);
    Solution so;
    TreeNode *ret = so.lowestCommonAncestor(root, p, q);
    int retval = ret->val;
    if (retval == vexpect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(vp);
        praw(vq);
        praw(vexpect);
        praw(retval);
        pnewline();
    }
}

int main() {
    test({-1, 0, 3, -2, 4, null, null, 8}, 8, 4, 0);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 0, 8, 1);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({1, 2}, 1, 2, 1);
    return 0;
}

/*
[-1,0,3,-2,4,null,null,8]
8
4

[3,5,1,6,2,0,8,null,null,7,4]
5
1
[3,5,1,6,2,0,8,null,null,7,4]
5
4
[1,2]
1
2
[3,5,1,6,2,0,8,null,null,7,4]
0
8

*/
