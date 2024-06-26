#include "../inc.h"

// in-order traverse
class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        int64_t vlast = INT64_MIN;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();

            if (root->val <= vlast) return false;
            vlast = root->val;

            root = root->right;
        }
        return true;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().isValidBST(root));
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
