#include "../inc.h"

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int found = 0;
        return helper(root, p, q, found);
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, int& found) {
        if (root == nullptr) return nullptr;
        int foundleft = found;
        int foundright = found;
        auto left = helper(root->left, p, q, foundleft);
        if (left != nullptr) return left;
        auto right = helper(root->right, p, q, foundright);
        if (right != nullptr) return right;
        if (root == p || root == q) ++found;
        found = found + foundleft + foundright;
        if (found >= 2) return root;
        return nullptr;
    }
};

void test(const vector<ComplexVal>& vals, int pv, int qv, int expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto p = treeFindUniqueNodeByVal(root, pv);
    auto q = treeFindUniqueNodeByVal(root, qv);
    Solution so;
    auto ret = so.lowestCommonAncestor(root, p, q);
    if (ret == nullptr || ret->val != expect) {
        print("not ok");
        print(vals);
        print(pv);
        print(qv);
        print(expect);
        print(ret);
        print();
    } else {
        print("ok");
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({3, 5, 1}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    return 0;
}