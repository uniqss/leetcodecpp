#include "../stl.h"

// recursive
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        helper(root, ret);
        return ret;
    }
    void helper(TreeNode* root, vector<int>& ret) {
        if (root != nullptr) {
            helper(root->left, ret);
            ret.push_back(root->val);
            helper(root->right, ret);
        }
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
