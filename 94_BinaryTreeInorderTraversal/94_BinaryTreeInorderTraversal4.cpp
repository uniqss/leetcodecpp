#include "../inc.h"

// threaded binary tree--不建议，会破坏结构，建议用下一种 threaded binary tree 解法
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ret.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                TreeNode* tmp = curr;
                prev->right = curr;
                curr = curr->left;
                tmp->left = nullptr;
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);

    auto ret = so.inorderTraversal(tree);
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
    test({4, 2, 6, 1, 3, 5, 7}, {1, 2, 3, 4, 5, 6, 7});
    test({1, null, 2, 3}, {1, 3, 2});
    test({}, {});
    test({1}, {1});
    return 0;
}
