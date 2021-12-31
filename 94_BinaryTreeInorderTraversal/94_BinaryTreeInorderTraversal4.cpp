#include "../stl.h"

// threaded binary tree
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
    vector<TreeNode*> allNodes;
    treeToVector(tree, allNodes);

    auto ret = so.inorderTraversal(tree);
    if (ret != expect) {
        praw("## not ok.");
        pvcomplex(root);
        pvraw(expect);
        pvraw(ret);
    } else {
        praw("ok.");
    }

    releaseAllTreeNodes(allNodes);
}

int main() {
    test({1, null, 2, 3}, {1, 3, 2});
    test({}, {});
    test({1}, {1});
    return 0;
}
