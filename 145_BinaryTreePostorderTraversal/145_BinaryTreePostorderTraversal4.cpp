#include "../stl.h"

// threaded binary tree 中文官方题解极为经典，居然一点都没动树的结构，连指针都还原的一模一样，简直完美！
class Solution {
   public:
    void addPath(TreeNode* root, vector<int>& ret) {
        size_t count = 0;
        while (root != nullptr) {
            ret.emplace_back(root->val);
            root = root->right;
            ++count;
        }
        std::reverse(ret.end() - count, ret.end());
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* p1 = root;
        TreeNode* p2 = nullptr;
        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    // p2->right == p1
                    p2->right = nullptr;
                    addPath(p1->left, ret);
                }
            }
            p1 = p1->right;
        }
        addPath(root, ret);

        return ret;
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
