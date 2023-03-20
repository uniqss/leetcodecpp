#include "../inc/inc.h"

// morris traverse.  This solution will break the tree's structure, left some tree node's right point to some ancestor(lead to infinite loop).
// 3.1 is better.
// Keep in mind: we SHOULD NOT break tree structure in some function only when we mean it!
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
    TreeAutoReleaser _(root);

    Solution so;
    bool ret = so.isValidBST(root);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(ret);
    }
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
