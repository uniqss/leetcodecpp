#include "../stl.h"

// morris traverse. This is ok, the tree will not be broken.
class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        int64_t vlast = INT64_MIN;
        TreeNode* curr = root;
        TreeNode* predecessor = nullptr;
        int changed = 0;
        bool ret = true;
        while (curr != nullptr) {
            predecessor = curr->left;
            if (predecessor != nullptr) {
                while (predecessor->right != nullptr && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = curr;
                    curr = curr->left;
                    ++changed;
                } else {
                    predecessor->right = nullptr;
                    --changed;
                    if (curr->val <= vlast) ret = false;
                    if (changed == 0 && !ret) return ret;

                    vlast = curr->val;

                    curr = curr->right;
                }
            } else {
                if (curr->val <= vlast) {
                    ret = false;
                    if (changed == 0) return ret;
                }
                vlast = curr->val;

                curr = curr->right;
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

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
