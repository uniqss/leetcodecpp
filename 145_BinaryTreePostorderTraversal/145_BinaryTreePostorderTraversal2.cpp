#include "../stl.h"

// stack 这个算法也很好，就是有个缺点，会破坏原本树的结构。做题可以，实际用的话不太适合，包括threaded-binary-tree也不太适合
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        TreeNode* curr = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            curr = stk.top();
            if (curr->left == nullptr && curr->right == nullptr) {
                ret.push_back(curr->val);
                stk.pop();
            } else {
                if (curr->right != nullptr) {
                    stk.push(curr->right);
                    curr->right = nullptr;
                }
                if (curr->left != nullptr) {
                    stk.push(curr->left);
                    curr->left = nullptr;
                }
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
    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});
    return 0;
}
