/*
https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1676-lowest-common-ancestor-of-a-binary-tree-iv

Constraints:
    The number of nodes in the tree is in the range [1, 104].
    -109 <= Node.val <= 109
    All Node.val are unique.
    All nodes[i] will exist in the tree.
    All nodes[i] are distinct.

    这个题目最终引导到了中文官方的那个dfs的神一样的解法。思路：
        当前节点空返回空
        当前节点在搜索节点列表中，返回当前节点
        左子树搜索结果为空，返回右子树搜索结果
        右子树搜索结果为空，返回左子树搜索结果
        否则，当前节点的左右子树搜索结果均非空。返回当前节点
    而且这个算法推演一下就会发现，性能非常高，如果搜索列表中节点足够多分布足够均匀的话，很快就会剪枝，而且幅度可观
*/

#include "../inc.h"

class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {}
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
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        pvraw(vals_node);
        praw(vexpect);
        praw(retval);
        pnewline();
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {4, 7}, 2);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {1}, 1);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {7, 6, 2, 4}, 5);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, {0, 1, 2, 3, 4, 5, 6, 7, 8}, 3);
    return 0;
}
