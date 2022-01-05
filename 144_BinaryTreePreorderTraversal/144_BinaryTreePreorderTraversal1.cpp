#include "../stl.h"

// recursive
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        helper(root, ret);
        return ret;
    }
    void helper(TreeNode* root, vector<int>& ret) {
        if (root == nullptr) return;
        ret.push_back(root->val);
        helper(root->left, ret);
        helper(root->right, ret);
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    vector<TreeNode*> allNodes;
    treeToVector(tree, allNodes);

    auto ret = so.preorderTraversal(tree);
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
    test({1, null, 2, 3}, {1, 2, 3});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {4, 2, 1, 3, 6, 5, 7});
    return 0;
}
