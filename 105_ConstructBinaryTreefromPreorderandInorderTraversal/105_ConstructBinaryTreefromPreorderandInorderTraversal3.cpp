#include "../inc.h"

// stack non-recursive solution
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};

void test(vector<int>&& preorder, vector<int>&& inorder, vector<ComplexVal>&& expect) {
    Solution so;
    TreeNode* ret = so.buildTree(preorder, inorder);
    TreeAutoReleaser _(ret);
    TreeNode* expect_tree = constructIntTree(expect);
    TreeAutoReleaser _etree(expect_tree);
    vector<int> vret;
    vector<int> vexpect;
    treeToIntVecLevelOrder(ret, vret);
    treeToIntVecLevelOrder(expect_tree, vexpect);
    if (vret == vexpect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(preorder);
        pvraw(inorder);
        pvcomplex(expect);
        pTree(expect_tree);
        pTree(ret);
    }
}

int main() {
    test({4, 2, 1, 3, 6, 5, 7}, {1, 2, 3, 4, 5, 6, 7}, {4, 2, 6, 1, 3, 5, 7});
    test({1, 2, 3}, {2, 3, 1}, {1, 2, null, null, 3});
    test({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    return 0;
}

/*
[1,2,3]
[2,3,1]
[1,2,null,null,3]


[3,9,20,15,7]
[9,3,15,20,7]
[-1]
[-1]

[3,9,20,null,null,15,7]
[-1]
*/