#include "../stl.h"

// morris traverse
class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        int64_t vlast = INT64_MIN;
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

                    if (curr->val <= vlast) return false;
                    vlast = curr->val;

                    curr = curr->right;
                }
            } else {
                if (curr->val <= vlast) return false;
                vlast = curr->val;

                curr = curr->right;
            }
        }

        return true;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    std::vector<TreeNode*> all_nodes;
    treeToVector(root, all_nodes);

    Solution so;
    bool ret = so.isValidBST(root);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
    }

    releaseAllTreeNodes(all_nodes);
}

int main() {
    test({2, 1, 3}, true);
    test({5, 1, 4, null, null, 3, 6}, false);
    return 0;
}

/*
[2,1,3]
[5,1,4,null,null,3,6]
true
false
*/
