#include "../stl.h"

// threaded binary tree 中文官方题解极为经典，居然一点都没动树的结构，连指针都还原的一模一样，简直完美！
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* curr = root;
        TreeNode* predecessor = nullptr;
        while (curr != nullptr) {
            predecessor = curr->left;
            if (predecessor != nullptr) {
                while (predecessor->right != nullptr && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr;
                    addRightReverse(ret, curr->left);
                    curr = curr->right;
                }
            } else {
                curr = curr->right;
            }
        }
        addRightReverse(ret, root);

        return ret;
    }
    void addRightReverse(vector<int>& ret, TreeNode* root) {
        size_t count = 0;
        while (root != nullptr) {
            ret.emplace_back(root->val);
            root = root->right;
            ++count;
        }
        std::reverse(ret.end() - count, ret.end());
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    vector<TreeNode*> allNodes;
    treeToVector(tree, allNodes);

    auto ret = so.postorderTraversal(tree);
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
    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});

    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});
    return 0;
}
