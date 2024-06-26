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
    std::unordered_map<TreeNode *, TreeNode *> fa_;

   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int dp = dfs(root, p);
        if (dp <= 0) return nullptr;
        int dq = dfs(root, q);
        if (dq <= 0) return nullptr;
        while (dp < dq) {
            q = fa_[q];
            --dq;
        }
        while (dq < dp) {
            p = fa_[p];
            --dp;
        }
        while (p != q) {
            p = fa_[p];
            q = fa_[q];
        }
        return p;
    }
    int dfs(TreeNode *root, TreeNode *n) {
        if (root == nullptr) return 0;
        int depth = 1;
        std::queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (root == n) return depth;
                if (root->left != nullptr) {
                    fa_[root->left] = root;
                    q.emplace(root->left);
                }
                if (root->right != nullptr) {
                    fa_[root->right] = root;
                    q.emplace(root->right);
                }
            }
            ++depth;
        }
        return 0;
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
