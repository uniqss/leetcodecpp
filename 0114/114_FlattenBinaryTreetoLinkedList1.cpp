#include "../inc.h"

class Solution {
   public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode *l = root->left, *r = root->right, *lr = l;
        if (l == nullptr) {
        } else if (r == nullptr) {
            root->left = nullptr;
            root->right = l;
        } else {
            while (lr->right != nullptr) lr = lr->right;
            lr->right = r;
            root->left = nullptr;
            root->right = l;
        }
        flatten(root->right);
    }
};

void test(vector<ComplexVal>&& vals) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution().flatten(root);
    TreeNode* root2 = constructIntTree(vals);
    vector<int> expect_vals, ret_vals;
    bool singleright = true;
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (curr->left != nullptr) {
            singleright = false;
            break;
        }
        curr = curr->right;
    }

    treeToIntVecPreOrder(root, ret_vals);
    treeToIntVecPreOrder(root2, expect_vals);
    assert_retnone(expect_vals == ret_vals && singleright);
}

int main() {
    test({1, 2, null, 3});
    test({1, 2});
    test({1, 2, 5, 3, 4, null, 6});
    test({});
    test({0});
    return 0;
}