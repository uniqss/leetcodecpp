/*
https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1676-lowest-common-ancestor-of-a-binary-tree-iv

Constraints:
    The number of nodes in the tree is in the range [1, 104].
    -109 <= Node.val <= 109
    All Node.val are unique.
    All nodes[i] will exist in the tree.
    All nodes[i] are distinct.
*/

#include "../inc.h"

class Solution {
   public:
    TreeNode *dfs(TreeNode *root, std::unordered_set<TreeNode *> &nodes) {
        if (root == nullptr) return nullptr;
        if (nodes.count(root) > 0) return root;
        TreeNode *left = dfs(root->left, nodes);
        TreeNode *right = dfs(root->right, nodes);
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
        std::unordered_set<TreeNode *> existed(nodes.begin(), nodes.end());
        return dfs(root, existed);
    }
};

void test(vector<ComplexVal> &&vals, vector<int> &&vals_node, int vexpect) {
    TreeNode *root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    vector<TreeNode *> nodes(vals_node.size(), nullptr);
    for (size_t i = 0; i < vals_node.size(); ++i) {
        nodes[i] = treeFindUniqueNodeByVal(root, vals_node[i]);
    }

    Solution so;
    TreeNode *ret = so.lowestCommonAncestor(root, nodes);
    int retval = ret->val;
    if (retval == vexpect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(vals_node);
        print(vexpect);
        print(retval);
        print();
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {4, 7}, 2);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {1}, 1);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {7, 6, 2, 4}, 5);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {0, 1, 2, 3, 4, 5, 6, 7, 8}, 3);
    return 0;
}
