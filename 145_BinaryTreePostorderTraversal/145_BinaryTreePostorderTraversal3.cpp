#include "../stl.h"

// stack 经典写法
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (curr->right == nullptr || curr->right == prev) {
                ret.push_back(curr->val);
                prev = curr;
                curr = nullptr;
            } else {
                stk.push(curr);
                curr = curr->right;
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
