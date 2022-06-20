#include "../inc.h"

class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* curr = root;
        TreeNode* predecessor;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                predecessor = curr->left;
                while (predecessor->right != nullptr && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr;
                    addReverse(curr->left, ret);
                    curr = curr->right;
                }
            } else {
                // ret.emplace_back(curr->val);
                curr = curr->right;
            }
        }
        addReverse(root, ret);
        return ret;
    }
    void addReverse(TreeNode* root, vector<int>& ret) {
        auto size = ret.size();
        while (root != nullptr) {
            ret.emplace_back(root->val);
            root = root->right;
        }
        reverse(ret.begin() + size, ret.end());
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);

    auto ret = so.postorderTraversal(tree);
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
    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});

    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});
    return 0;
}
