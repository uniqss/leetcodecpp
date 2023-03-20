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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        auto ret = dfs(root, p, q);
        if (ret.second >= 2) return ret.first;
        return nullptr;
    }
    pair<TreeNode *, int> dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return {nullptr, 0};

        pair<TreeNode *, int> left = dfs(root->left, p, q);
        if (left.second >= 2) return left;
        if (left.second >= 1 && (root == p || root == q)) return {root, 2};

        pair<TreeNode *, int> right = dfs(root->right, p, q);
        if (right.second >= 2) return right;
        if (right.second >= 1 && (root == p || root == q)) return {root, 2};

        if (left.second >= 1 && right.second >= 1) return {root, 2};
        if (left.second + right.second >= 1 || (root == p || root == q)) return {root, 1};

        return {nullptr, 0};
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
