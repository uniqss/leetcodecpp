#include "../inc.h"

// threaded-binary-tree (morris) 中文官方解法，非常完美，不破坏树结构
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* predecessor = nullptr;
        while (root != nullptr) {
            predecessor = root->left;
            if (predecessor != nullptr) {
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    ret.push_back(root->val);
                    root = root->right;
                    predecessor->right = nullptr;
                }
            } else {
                ret.push_back(root->val);
                root = root->right;
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    save4print(root);
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);
    assert_eq_ret(expect, Solution().inorderTraversal(tree));
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {1, 2, 3, 4, 5, 6, 7});
    test({1, null, 2, 3}, {1, 3, 2});
    test({}, {});
    test({1}, {1});
    return 0;
}
