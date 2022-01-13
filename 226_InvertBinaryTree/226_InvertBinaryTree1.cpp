#include "../stl.h"

// recursive
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        return helper(root);
    }
    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        helper(root->right);
        helper(root->left);
        return root;
    }
};

void test(const vector<int>& vals, const vector<int>& expect) {
    TreeNode* root = constructIntBinaryTreeLayerOrder(vals);
    vector<TreeNode*> allnodes;
    treeToVector(root, allnodes);

    Solution so;
    TreeNode* ret = so.invertTree(root);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    if (ret_vec != expect) {
        praw("not ok.");
        pvraw(vals);
        pvraw(expect);
        pvraw(ret_vec);
    } else {
        praw("ok.");
    }

    releaseAllTreeNodes(allnodes);
}

int main() {
    test({4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1});
    test({2, 1, 3}, {2, 3, 1});
    test({}, {});
    return 0;
}

/*
[4,2,7,1,3,6,9]
[2,1,3]
[]
*/
