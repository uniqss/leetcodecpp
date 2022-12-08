/*

https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1650-lowest-common-ancestor-of-a-binary-tree-iii

The number of nodes in the tree is in the range [2, 105].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q exist in the tree.
*/

#include "../stl.h"
#include "../complexval.h"
#include "../TreeWithParentHelper.h"

#define null nullptr

class Solution {
    std::unordered_set<Node*> existed;

   public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
    }
};

void test(vector<ComplexVal>&& vals, int vp, int vq, int vexpect) {
    Node* root = constructIntTree(vals);
    TreeWithParentAutoReleaser _(root);
    Node* p = treeWithParentFindUniqueNodeByVal(root, vp);
    Node* q = treeWithParentFindUniqueNodeByVal(root, vq);
    Solution so;
    Node* ret = so.lowestCommonAncestor(p, q);
    if (ret == nullptr || ret->val != vexpect) {
        print("not ok");
    } else {
        print("ok.");
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({1, 2}, 1, 2, 1);
    return 0;
}
