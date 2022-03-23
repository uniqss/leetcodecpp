/*
https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1644-lowest-common-ancestor-of-a-binary-tree-ii

Constraints:
    The number of nodes in the tree is in the range [1, 104].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
Follow up: Can you find the LCA traversing the tree, without checking nodes existence?
*/

#include "../inc.h"

class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}
};

void test(vector<ComplexVal> &&vals, int vp, int vq, ComplexVal vexpect) {
    TreeNode *root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode *p = treeFindUniqueNodeByVal(root, vp);
    TreeNode *q = treeFindUniqueNodeByVal(root, vq);
    TreeNode tmp_p(vp);
    if (p == nullptr) p = &tmp_p;
    TreeNode tmp_q(vq);
    if (q == nullptr) q = &tmp_q;
    Solution so;
    TreeNode *ret = so.lowestCommonAncestor(root, p, q);
    if (vexpect.IsNullptr()) {
        if (ret == nullptr) {
            praw("ok.");
        } else {
            praw("expected: null");
            praw(ret->val);
            pnewline();
        }
    } else {
        if (ret == nullptr) {
            praw(vexpect.vali);
            praw("ret: null");
            pnewline();
        } else {
            if (ret->val == vexpect.vali) {
                praw("ok.");
            } else {
                praw(vexpect.vali);
                praw(ret->val);
                pnewline();
            }
        }
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 3, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 10, null);
    return 0;
}
