/*

https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1650-lowest-common-ancestor-of-a-binary-tree-iii

The number of nodes in the tree is in the range [2, 105].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q exist in the tree.

有父指针的树简直太幸福了，可以逆向走整个树，时间空间都超幸福  超时空的幸福
*/

#include "../stl.h"
#include "../complexval.h"
#include "../TreeWithParentHelper.h"

#define null nullptr

class Solution {
    std::unordered_set<Node*> existed;

   public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        existed.clear();
        while (true) {
            if (p != nullptr) {
                if (existed.find(p) != existed.end()) return p;
                existed.insert(p);
                p = p->parent;
            }
            if (q != nullptr) {
                if (existed.find(q) != existed.end()) return q;
                existed.insert(q);
                q = q->parent;
            }
            if (p == nullptr && q == nullptr) break;
        }
        return nullptr;
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
        if (ret == nullptr) {
            print("returned null");
        } else {
            print(vexpect);
            print(ret->val);
        }
        print();
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
