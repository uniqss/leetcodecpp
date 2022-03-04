#include "../inc.h"

// recursive
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

void test(const vector<int>& vals, const vector<int>& expect) {
    TreeNode* root = constructIntBinaryTreeLayerOrder(vals);
    TreeAutoReleaser _(root);

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
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {4, 6, 2, 7, 5, 3, 1});
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
