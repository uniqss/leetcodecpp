#include "../stl.h"

// threaded-binary-tree (morris) 中文官方解法，非常完美，不破坏树的任何结构
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    ret.emplace_back(root->val);
                    root = root->left;
                    continue;
                } else {
                    root = root->right;
                    predecessor->right = nullptr;
                }
            } else {
                ret.emplace_back(root->val);
                root = root->right;
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);

    auto ret = so.preorderTraversal(tree);
    if (ret != expect) {
        praw("## not ok.");
        pvcomplex(root);
        pvraw(expect);
        pvraw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({1, 4, 3, 2}, {1, 4, 2, 3});
    test({1, null, 2, 3}, {1, 2, 3});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {4, 2, 1, 3, 6, 5, 7});

    return 0;
}
