/*
https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1644-lowest-common-ancestor-of-a-binary-tree-ii

Constraints:
    The number of nodes in the tree is in the range [1, 104].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
Follow up: Can you find the LCA traversing the tree, without checking nodes existence?
*/

/*
这个破网站给出的解，注意这个解法要遍历整棵树，，，  当pq均出现在左的子树中时，有很大的优化空间(不用搜索右子树)，详见21的解
*/

#include "../inc/inc.h"

class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        auto ret = dfs(root, p, q);
        if (ret.second < 2) return nullptr;
        return ret.first;
    }
    pair<TreeNode *, int> dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return {nullptr, 0};
        auto retl = dfs(root->left, p, q);
        auto retr = dfs(root->right, p, q);
        if (root == p || root == q) return {root, 1 + retl.second + retr.second};
        if (retl.second + retr.second == 2) return {root, 2};
        return retl.first ? retl : retr;
    }
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
            print("ok.");
        } else {
            print("expected: null");
            print(ret->val);
            print();
        }
    } else {
        if (ret == nullptr) {
            print(vexpect.vali);
            print("ret: null");
            print();
        } else {
            if (ret->val == vexpect.vali) {
                print("ok.");
            } else {
                print(vexpect.vali);
                print(ret->val);
                print();
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
